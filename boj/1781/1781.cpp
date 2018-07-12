#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii; // first : deadline, second : award

ll N; // 숙제의 개수
ii prob[222222];

ll heap[222222];
ll items;
void push(ll item){
	items++;
	heap[items]=item;
	ll curIdx=items/2;
	while(curIdx>=1){
		ll child=-1;
		if(curIdx*2<=items) child=curIdx*2;
		if(curIdx*2+1<=items && heap[curIdx*2]<heap[curIdx*2+1]) child=curIdx*2+1;

		if(child>=0 && heap[curIdx]<heap[child]){
			ll tmp=heap[curIdx];
			heap[curIdx]=heap[child];
			heap[child]=tmp;

			curIdx/=2;	
		}
		else break;
	}
}

ll pop(){
	ll top=heap[1];
	heap[1]=heap[items];
	items--;

	ll curIdx=1;
	while(curIdx*2<=items){
		ll child=-1;	
		if(curIdx*2<=items) child=curIdx*2;
		if(curIdx*2+1<=items && heap[curIdx*2]<heap[curIdx*2+1]) child=curIdx*2+1;

		if(child>=0 && heap[curIdx]<heap[child]){
			ll tmp=heap[curIdx];
			heap[curIdx]=heap[child];
			heap[child]=tmp;

			curIdx=child;
		}
		else break;
	}
	return top;
}

int main(void){
	scanf("%lld",&N);

	items=0;
	for(ll i=0; i<N; i++)
		scanf("%lld %lld",&prob[i].first, &prob[i].second);
	sort(prob,prob+N); // deadline 오름차순 정렬

	ll ans=0;
	ll probIdx=N-1;

	for(ll time=N; time>=1; time--){ // 늦은 시점부터 고려
		while(probIdx>=0 && prob[probIdx].first>=time){ // 현재 시간에서 deadline을 만족하는 문제는 힙에 push
			push(prob[probIdx].second);
			probIdx--;
		}

		if(items>0) ans+=pop(); // 현재 시간에 얻을 수 있는 최대 라면 수를 더해줌
	}
	printf("%lld\n",ans);
	return 0;
}
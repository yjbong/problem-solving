#include <cstdio>
#include <queue>
#include <utility>
#define INF 100000000000000000ll

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int n; // 전체 문제의 수
int m; // 보너스 점수를 얻기 위해 필요한 코인의 수

// 문제 번호는 1 ~ n 번
ll p[500001]; // p[i] = i번 문제를 맞추거나 틀릴 때 가감되는 점수
ll b[500001]; // b[i] = i번 문제를 맞춰서 코인이 m개가 되었을 때 얻는 보너스 점수

ll s[500001]; // s[i] = p[1]+p[2]+ ... +p[i]
ll d[500001]; // d[i] = i번 문제를 풀어서 코인이 0개가 된 경우에 그때까지 얻을 수 있는 최대 점수

priority_queue <ii> pq; // max heap

ll max2(ll a, ll b){ return a>b?a:b; }
int main(void){

	// 입력
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++) scanf("%lld",&p[i]);
	for(int i=1; i<=n; i++) scanf("%lld",&b[i]);

	// s배열 계산
	s[0]=0;
	for(int i=1; i<=n; i++) s[i]=s[i-1]+p[i];

	// d배열 초기화
	d[0]=0;
	for(int i=1; i<=n; i++) d[i]=-INF;

	// max heap 초기화
	pq.push(make_pair(d[0]-s[0], 0));

	// d배열 계산
	for(int i=1; i<=n; i++){

		if(i-m>=0) d[i]=max2(d[i],d[i-m]+s[i]-s[i-m] + b[i]);

		// 이 부분은 max heap으로 변경 필요
		/*
		for(int j=max2(i-m+1,0); j<i; j++){
			d[i]=max2(d[i],d[j]+s[i-1]-s[j] - p[i]);
		}
		*/

		// max heap 이용
		ll tmp=-INF;
		while(!pq.empty()){
			ii t=pq.top();
			if(t.second >= max2(i-m+1, 0)){
				tmp=t.first;
				break;
			}
			else pq.pop();
		}
		d[i]=max2(d[i], tmp+s[i-1]-p[i]);

		// max heap 업데이트
		pq.push(make_pair(d[i]-s[i], i));
	}
	
	// 답 계산
	ll ans=-INF;
	for(int i=max2(n-m+1,0); i<=n; i++){
		ans=max2(ans,d[i]+s[n]-s[i]);		
	}
	printf("%lld\n",ans);

	return 0;
}
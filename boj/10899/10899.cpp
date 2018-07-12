#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll P; // 대회 시간
int N; // 문제의 개수
ll t[100000]; // t[i] = i번 문제를 푸는데 걸리는 시간

int main(void){
	scanf("%lld %d",&P,&N);
	for(int i=0; i<N; i++) scanf("%lld",&t[i]);
	sort(t,t+N);

	ll solves=0; // 풀 수 있는 문제의 개수
	ll sum=0; // 그 문제들을 푸는데 걸리는 총 시간
	for(int i=0; i<N; i++){
		if(sum+t[i]<P){
			sum+=t[i];
			solves++;	
		}
		else break;
	}

	ll penalty=0; // 총 페널티
	ll time=P-1; // 페널티를 최대로 하기 위해, 가장 시간이 짧은 문제를 시점 P-1에 제출한다.
	for(int i=0; i<solves; i++){
		penalty+=time;
		time-=t[i]; // 페널티를 최대로 하기 위해, i+1번 문제는 i번 문제를 풀기 시작했을 때 제출한다.
	}
	printf("%lld %lld\n",solves,penalty);
	return 0;
}
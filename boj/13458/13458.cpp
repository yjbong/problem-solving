#include <cstdio>
typedef long long ll;
ll N; // 시험장 개수
ll A[1000000];
ll B; // 총감독관 1명이 감시할 수 있는 응시생의 수
ll C; // 부감독관 1명이 감시할 수 있는 응시생의 수
int main(void){
	scanf("%lld",&N);
	for(int i=0; i<N; i++) scanf("%lld",&A[i]);
	scanf("%lld %lld",&B,&C);
	ll ans=0;
	for(int i=0; i<N; i++){		
		// 총감독관 1명 투입
		ans++;
		A[i]-=B;
		// 응시생이 남은 경우 부감독관 투입
		if(A[i]>0) ans+=A[i]/C+(A[i]%C?1:0);
	}
	printf("%lld\n",ans);
	return 0;
}
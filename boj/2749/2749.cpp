#include <cstdio>
#define MODNUM 1000000ll
typedef long long ll;
ll f[61][2][2]; // f[i] = f[0]^(2^i) (f[0]은 2*2 행렬)
int main(void){

	// f[0] = |0 1|
	//	  |1 1|
	f[0][0][0]=0; f[0][0][1]=1;
	f[0][1][0]=1; f[0][1][1]=1;

	// f[1]~f[60] 계산
	for(ll i=1; i<=60; i++){
		f[i][0][0]=(f[i-1][0][0]*f[i-1][0][0]+f[i-1][0][1]*f[i-1][1][0])%MODNUM;
		f[i][0][1]=(f[i-1][0][0]*f[i-1][0][1]+f[i-1][0][1]*f[i-1][1][1])%MODNUM;
		f[i][1][0]=(f[i-1][1][0]*f[i-1][0][0]+f[i-1][1][1]*f[i-1][1][0])%MODNUM;
		f[i][1][1]=(f[i-1][1][0]*f[i-1][0][1]+f[i-1][1][1]*f[i-1][1][1])%MODNUM;
	}

	ll n;
	scanf("%lld",&n);

	ll mat[2][2]; // |0 1|n 값을 저장할 행렬
		      // |1 1|

	// mat을 항등행렬 I로 초기화
	mat[0][0]=1; mat[0][1]=0;
	mat[1][0]=0; mat[1][1]=1;

	// mat 계산
	for(ll i=0; i<=60; i++){
		if(n&(1ll<<i)){
			ll cur00,cur01,cur10,cur11;
			cur00=(f[i][0][0]*mat[0][0]+f[i][0][1]*mat[1][0])%MODNUM;
			cur01=(f[i][0][0]*mat[0][1]+f[i][0][1]*mat[1][1])%MODNUM;
			cur10=(f[i][1][0]*mat[0][0]+f[i][1][1]*mat[1][0])%MODNUM;
			cur11=(f[i][1][0]*mat[0][1]+f[i][1][1]*mat[1][1])%MODNUM;
			mat[0][0]=cur00;
			mat[0][1]=cur01;
			mat[1][0]=cur10;
			mat[1][1]=cur11;
		}
	}

	// n번째 피보나치 수 계산
	ll ans=mat[0][1];
	printf("%lld\n",ans);	
	return 0;
}
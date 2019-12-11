#include <cstdio>
#define MOD 1000000007ll
using namespace std;
typedef long long ll;
ll A; // 밑
ll X; // 지수
 
ll P[64]; // P[i]=(A^(2^i)) % MOD
 
int main(void) {
    scanf("%lld %lld",&A,&X);
    
    // DP
    P[0]=A%MOD;
    for(int i=1; i<64; i++) P[i]=(P[i-1]*P[i-1])%MOD;
 
    // A^P 계산
    ll ans=1;
    for(int i=0; i<64; i++) if(X&(1ll<<i)) ans=(ans*P[i])%MOD;
    printf("%lld\n",ans);
 
    return 0;
}
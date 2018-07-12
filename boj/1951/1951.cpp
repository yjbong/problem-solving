#include <cstdio>
#define MOD 1234567ll
typedef long long ll;
ll acc[15];
ll pow[15];
int main(void){

    acc[0]=0;
    acc[1]=9;
    for(int i=2; i<15; i++) acc[i]=acc[i-1]+(acc[i-1]-acc[i-2])*10/(i-1)*i;
    pow[0]=0;
    pow[1]=1;
    for(int i=2; i<15; i++) pow[i]=pow[i-1]*10;

    ll n;
    scanf("%lld",&n);
    ll dgt=0;
    ll t=n;
    while(t>0){
        t/=10;
        dgt++;
    }
    ll sol=(acc[dgt-1]+(n-pow[dgt]+1)*dgt)%MOD;
    printf("%lld\n",sol);
    return 0;
}
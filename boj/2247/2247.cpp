#include<cstdio>
#include<cmath>
typedef long long ll;
ll n,sqrt_n;
ll sol=0;
int main(void){
    scanf("%lld",&n);
    sqrt_n = (ll)(sqrt(n));
    for(ll i=2; i<=sqrt_n; i++)
        sol = ( sol+i*(n/i-i) + (n/i)*(n/i+1)/2 - (i-1)*i/2 ) % 1000000;
    printf("%lld\n",sol);
    return 0;
}
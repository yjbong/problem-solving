#include <cstdio>
typedef long long ll;
int c;
ll n,k;
ll max2(ll a,ll b){
    return a>b?a:b;
}
int main(void){
    scanf("%d",&c);
    while(c--){
        scanf("%lld %lld",&n,&k);
        ll ans=0;
        for(ll i=0; i<=n && i*k<100000; i++)
            ans=max2(ans,i*k*9/10+((n-i)*k)/10000*10000);
        printf("%lld\n",ans);
    }
    return 0;
}
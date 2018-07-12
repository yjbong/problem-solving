#include <cstdio>
typedef long long ll;
bool p[1000001];
int main(void){

    ll n;
    scanf("%lld",&n);
    p[0]=p[1]=true;
    for(ll i=2; i<=n; i++)
        if(!p[i]) for(ll j=i*2; j<=n; j+=i) p[j]=true;

    ll sol=1;
    for(ll i=2; i<=n; i++){
        if(!p[i]){
            ll cur=1;
            ll t=n;
            while(t>=i){
                t/=i;
                cur*=i;
            }
            sol=(sol*cur)%987654321ll;
        }
    }
    printf("%lld\n",sol);
    return 0;
}
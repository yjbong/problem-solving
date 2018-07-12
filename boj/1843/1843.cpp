#include <cstdio>
typedef long long ll;
ll d[100];
ll p[50000];
ll ps;
bool c[500001];

bool binsearch(ll key){
    int l,m,r;

    l=0,r=ps-1;
    while(l<=r){
        m=(l+r)/2;
        if(p[m]<key) l=m+1;
        else if(p[m]>key) r=m-1;
        else return true;
    }
    return false;
}

int main(void){

    ll n;
    scanf("%lld",&n);

    ////////////////////////////////////////////
    ll asol=0;
    for(ll i=1; i<=n; i++){
        asol+=i/2;
        if(i%2==0) asol--;
    }
    printf("%lld\n",asol);

    ////////////////////////////////////////////
    ll bsol=0;
    ll ds=0;
    for(ll i=1; i<=n; i++) if(n%i==0) d[ds++]=i;
    for(ll i=0; i<ds; i++){
        for(ll j=i; j<ds; j++){
            for(ll k=j; k<ds; k++){
                if(d[i]+d[j]==d[k]){
                    bsol++;
                    break;
                }
            }
        }
    }
    printf("%lld\n",bsol);

    ////////////////////////////////////////////
    ll csol=0;
    c[0]=c[1]=true;
    for(ll i=2; i<=n; i++)
        if(!c[i]) for(ll j=i*2; j<=n; j+=i) c[j]=true;

    ps=0;
    for(ll i=0; i<=n; i++) if(!c[i]) p[ps++]=i;
    for(ll i=0; i<ps; i++)
        if(binsearch(p[i]-2)) csol++;

    printf("%lld\n",csol);
    return 0;
}
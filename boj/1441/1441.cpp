#include <cstdio>
#define SWAP(a,b,tmp) {tmp=a; a=b; b=tmp;}
typedef long long ll;

ll n,l,r;
ll a[18];

ll lcm(ll a, ll b){

    ll tmp;
    ll sa,sb;
    sa=a; sb=b;
    if(a<b) SWAP(a,b,tmp);
    while(b>0){
        a=a%b;
        SWAP(a,b,tmp);
    }
    return sa*sb/a;
}

int main(void){

    scanf("%lld %lld %lld",&n,&l,&r);
    for(ll i=0; i<n; i++) scanf("%lld",&a[i]);

    ll sol=0;
    for(ll i=1; i<(1<<n); i++){
        ll t=i;
        ll j=0;
        ll cur_div=1;
        ll bits=0;
        bool over=false;
        while(t>0){
            if(t%2){
                cur_div = lcm(cur_div, a[j]);
                bits++;
            }
            if(cur_div>r){
                over=true;
                break;
            }

            t/=2;
            j++;
        }

        if(bits%2) sol+=(r/cur_div - (l-1)/cur_div);
        else sol-=(r/cur_div - (l-1)/cur_div);
    }

    printf("%lld\n",sol);
    return 0;
}
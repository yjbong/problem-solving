#include <cstdio>
#include <algorithm>
#define IMP -1000000000000000000ll
typedef long long ll;
using namespace std;
ll n,s;

typedef struct{
    ll d;
    ll x;
    ll y;
    ll t;
}INFO;

INFO a[7000];

bool cmp(const INFO a1, const INFO a2){
    if(a1.t < a2.t) return true;
    else return false;
}

int main(void){

    scanf("%lld %lld",&n,&s);
    a[0].d=a[0].x=a[0].y=a[0].t=0;
    for(ll i=1; i<=n; i++){
        a[i].d=IMP;
        scanf("%lld %lld %lld",&(a[i].x),&(a[i].y),&(a[i].t));
    }
    sort(a,a+n+1,cmp);

    for(ll i=1; i<=n; i++){
        for(ll j=0; j<i; j++){
            if(a[j].d>IMP){
                if( ((a[i].t-a[j].t)*s)*((a[i].t-a[j].t)*s) >= (a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y) ){
                    if(a[i].d<a[j].d+1) a[i].d=a[j].d+1;
                }
            }
        }
    }

    ll max=0;
    for(ll i=0; i<=n; i++)
        if(max<a[i].d) max=a[i].d;

    printf("%lld\n",max);
    return 0;
}
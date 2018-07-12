#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll m[100000],ms;
ll p[100000],ps;
bool cmp(ll a, ll b){
    if(a<b) return false;
    else return true;
}

int main(void){

    int n;
    ll sol=0;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        ll c;
        scanf("%lld",&c);
        if(c<=0) m[ms++]=c;
        else if(c==1) sol++;
        else p[ps++]=c;
    }

    sort(m,m+ms);
    if(ms%2) sol+=m[--ms];
    for(int i=0; i<ms; i+=2) sol+=m[i]*m[i+1];

    sort(p,p+ps,cmp);
    if(ps%2)  sol+=p[--ps];
    for(int i=0; i<ps; i+=2) sol+=p[i]*p[i+1];

    printf("%lld\n",sol);
    return 0;
}
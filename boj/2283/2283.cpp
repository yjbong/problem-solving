#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

ll d[1000001];
ll s[1000001];
ll n,k;

ii line[1000001];
priority_queue <ll> pq;

ll binsearch(ll l, ll r, ll key){
    ll m,ret=-1;
    while(l<=r){
        m=(l+r)/2;
        if(key<s[m]) r=m-1;
        else if(key>s[m]) l=m+1;
        else{
            ret=m;
            r=m-1;
        }
    }
    return ret;
}

int main(void){

    scanf("%lld %lld",&n,&k);
    for(ll i=0; i<n; i++) scanf("%lld %lld",&(line[i].first), &(line[i].second));
    sort(line,line+n);

    ll cur=0;
    for(ll i=0; i<=1000000; i++){
        while(cur<n && line[cur].first < i){
            if(line[cur].first < line[cur].second){
                pq.push(-line[cur].second);
            }
            cur++;
        }
        d[i]=pq.size();
        while(!pq.empty() && (-pq.top())==i) pq.pop();
    }

    s[0]=d[0];
    for(ll i=1; i<=1000000; i++)
        s[i]=s[i-1]+d[i];

    bool ok=false;
    for(ll i=0; i<=1000000; i++){
        ll b;
        ll key=s[i]+k;
        if((b=binsearch(i+1,1000000,key))>=0){
            ok=true;
            printf("%lld %lld\n",i,b);
            break;
        }
    }

    if(!ok) printf("0 0\n");
    return 0;
}
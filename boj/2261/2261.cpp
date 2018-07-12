#include <cstdio>
#include <utility>
#include <algorithm>
#include <set>
#define INF 100000000ll
using namespace std;
typedef long long ll;
typedef pair<ll,ll> llll;
llll p[111111];
ll dst(llll a, llll b){
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}
set <llll> s;
set <llll>::iterator it,itl,itu;
int main(void){

    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%lld %lld",&(p[i].first),&(p[i].second));
    sort(p,p+n);

    ll d;
    if(n==1) d=0;
    else if(n==2) d=dst(p[0],p[1]);
    else{
        d=dst(p[0],p[1]);

        s.insert(llll(p[0].second, p[0].first));
        s.insert(llll(p[1].second, p[1].first));

        int left=0;
        for(int i=2; i<n; i++){
            if(d==0) break;
            while(!s.empty() && (p[i].first-p[left].first)*(p[i].first-p[left].first)>d){
                s.erase(llll(p[left].second, p[left].first));
                left++;
            }

            itl=s.lower_bound(llll(p[i].second-d, -INF));
            itu=s.upper_bound(llll(p[i].second+d, INF));
            for(it=itl; it != itu; it++){
                ll cd=((it->first)-p[i].second)*((it->first)-p[i].second)+((it->second)-p[i].first)*((it->second)-p[i].first);
                if(d>cd) d=cd;
            }
            s.insert(llll(p[i].second, p[i].first));
        }
    }

    printf("%lld\n",d);
    return 0;
}
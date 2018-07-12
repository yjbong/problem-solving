#include <cstdio>
#include <vector>
#include <utility>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
vector <ii> v;
ll n,p,q;
ll go(ll n){
    if(n==0) return 1;
    for(int i=0; i<v.size(); i++)
        if(v[i].first==n) return v[i].second;
    ll ret=go(n/p)+go(n/q);
    v.push_back(make_pair(n,ret));
    return ret;
}
int main(void){
    scanf("%lld %lld %lld",&n,&p,&q);
    printf("%lld\n",go(n));
    return 0;
}
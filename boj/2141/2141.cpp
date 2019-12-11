#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii; // first: X, second: A
int N; // 마을의 수
vector<ii> v;
int main() {
    scanf("%d",&N);
    ll totA=0;
    for(int i=0; i<N; i++){
        ll X,A;
        scanf("%lld %lld",&X,&A); totA+=A;
        v.push_back(make_pair(X,A));
    }
    sort(v.begin(),v.end());
 
    ll i, left=0, right=totA;
    for(i=0; i<N; i++){
        left+=v[i].second, right-=v[i].second;
        if(left>=right) break; // cross가 일어나는 시점의 i를 기억
    }
 
    printf("%lld\n",v[i].first);
    return 0;
}
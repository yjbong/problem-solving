#include <cstdio>
#include <stack>
using namespace std;
typedef long long ll;
int K;
stack <ll> s;
int main() {
    scanf("%d",&K);
    for(int i=0; i<K; i++){
        ll n;
        scanf("%lld",&n);
        if(n==0){ if(!s.empty()) s.pop(); }
        else s.push(n);
    }
    ll ans=0;
    while(!s.empty()){ ans+=s.top(); s.pop(); }
    printf("%lld\n",ans);
    return 0;
}
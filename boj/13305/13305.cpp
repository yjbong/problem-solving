#include <cstdio>
#include <queue>
using namespace std;
typedef long long ll;
int N;
ll dist[99999];
ll price[100000];
 
int main() {
    scanf("%d",&N);
    for(int i=0; i<N-1; i++)
        scanf("%lld",&dist[i]);
    for(int i=0; i<N; i++)
        scanf("%lld",&price[i]);
 
    ll best=price[0];
    ll ans=0;
    for(int i=0; i<N-1; i++){
        ans+=best*dist[i];
        if(best>price[i+1]) best=price[i+1];
    }
    printf("%lld\n",ans);
	return 0;
}
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
 
ll N,M;
int primes[10];
vector<ll> primeProducts[11];
 
void getPrimeProducts(ll curNum, int idx, int numProducts, bool add){
    if(add) primeProducts[numProducts].push_back(curNum);
    if(idx<N){
        // primes[idx] 를 곱한다
        getPrimeProducts(curNum*primes[idx],idx+1,numProducts+1,true);
        // primes[idx] 를 곱하지 않는다
        getPrimeProducts(curNum,idx+1,numProducts,false);
    }
}
 
int main() {
    scanf("%lld %lld",&N,&M);
    for(int i=0; i<N; i++) scanf("%d",&primes[i]);
    getPrimeProducts(1,0,0,true);
    ll ans=0;
    for(int i=1; i<=N; i++){
        for(int j=0; j<primeProducts[i].size(); j++){
            if(i%2) ans+=M/primeProducts[i][j];
            else ans-=M/primeProducts[i][j];
        }
    }
    printf("%lld\n",ans);
	return 0;
}
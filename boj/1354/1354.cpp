#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;

ll n,p,q,x,y;
map <ll, ll> cache;

ll solve(ll num){
	if(num<=0) return 1;
	else if(cache.find(num)!=cache.end()) return cache.find(num)->second;
	else{
		ll result = solve(num/p-x) + solve(num/q-y);
		cache.insert(make_pair(num,result));
		return result;
	}
}
int main(void){
	scanf("%lld %lld %lld %lld %lld",&n,&p,&q,&x,&y);
	printf("%lld\n",solve(n));
	return 0;
}
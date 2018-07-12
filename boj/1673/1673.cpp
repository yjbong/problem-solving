#include <cstdio>
typedef long long ll;
int main(void){
	ll n,k;
	while(scanf("%lld %lld",&n,&k)==2){
		ll ans=n;
		ll coupons=n;
		while(coupons>=k){
			ll freeGet=coupons/k;
			ans+=freeGet;
			coupons%=k;
			coupons+=freeGet;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
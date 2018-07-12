#include <cstdio>
typedef long long ll;
ll a[1111];
int main(void){

	ll n,d;
	scanf("%lld",&n);
	for(ll i=0; i<n; i++) scanf("%lld",&a[i]);
	scanf("%lld",&d);

	ll sol=0;
	for(ll i=0; i<n; i++){
		sol+=a[i]/d;
		if(a[i]%d) sol++;
	}
	printf("%lld\n",sol*d);
	return 0;
}
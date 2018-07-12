#include <cstdio>
typedef long long ll;
ll gcd(ll a, ll b){
	if(b==0) return a;
	else return gcd(b,a%b);
}
ll lcm(ll a, ll b){
	return a*b/gcd(a,b);
}
int main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		ll a,b;
		scanf("%lld %lld",&a,&b);
		printf("%lld\n",lcm(a,b));
	}
	return 0;
}
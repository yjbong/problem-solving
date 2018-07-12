#include <cstdio>
typedef long long ll;
int t,n;
ll A[100];
ll gcd(ll a, ll b){
	if(b==0) return a;
	else return gcd(b,a%b);
}
int main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0; i<n; i++) scanf("%lld",&A[i]);
		ll ans=0;
		for(int i=0; i<n; i++)
			for(int j=i+1; j<n; j++)
				ans+=gcd(A[i],A[j]);
		printf("%lld\n",ans);
	}
	return 0;
}
#include <cstdio>
typedef long long ll;

int n;
ll a[100000];
ll s[100000]; // s[i]=a[0]+a[1]+...+a[i]
int main(void){

	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%lld",&a[i]);

	s[0]=0;
	for(int i=1; i<n; i++) s[i]=s[i-1]+a[i];

	ll ans=0;
	for(int i=0; i<n; i++) ans+=a[i]*(s[n-1]-s[i]);
	
	printf("%lld\n",ans);
	return 0;
}
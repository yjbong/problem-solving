#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int n;
ll a[10001];
ll d[10001];
ll max2(ll a, ll b){ return a>b?a:b; }
int main(void){
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	d[0]=0;
	for(int i=1; i<=n; i++){
		d[i]=d[i-1]+a[i];
		if(i>=2) d[i]=max2(d[i],d[i-2]+a[i]*a[i-1]);
	}
	printf("%lld\n",d[n]);
	return 0;
}
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
ll f[111111];

ll binsearch(ll left, ll right, ll key){

	ll mid;
	ll ret=-1;
	while(left<=right){
		mid=(left+right)/2;
		if(f[mid]*10 < key*9) left=mid+1;
		else if(f[mid]*10 >= key*9){
			ret=mid;
			right=mid-1;
		}
	}
	return ret;
}

int main(void){

	ll n;
	scanf("%lld",&n);
	for(int i=0; i<n; i++) scanf("%lld",&f[i]);
	
	long long sol=0;
	sort(f,f+n);
	for(ll i=n-1; i>=1; i--){
		ll idx=binsearch(0,i-1,f[i]);
		if(idx>=0) sol+=(i-idx);
	}
	printf("%lld\n",sol);
	return 0;
}
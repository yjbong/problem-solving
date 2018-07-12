#include <cstdio>
#define INF 1000000000000000ll
typedef long long ll;
ll x,y,z,ans;
int main(void){
	while(scanf("%lld %lld",&x,&y)==2){
		ll z=(y*100)/x;
		ll left=1, right=INF;
		ll ans=INF;
		while(left<=right){
			ll mid=(left+right)/2;
			ll curZ=((y+mid)*100)/(x+mid);
			if(curZ>z){
				if(ans>mid) ans=mid;
				right=mid-1;
			}
			else left=mid+1;
		}
		if(ans<INF) printf("%lld\n",ans);
		else printf("-1\n");
	}
	return 0;
}
#include <cstdio>
#include <cmath>
typedef long long ll;
ll maxBox(double A, ll L, ll W, ll H){ // max # of A*A*A size boxes in the L*W*H box
	return (ll)(L/A) * (ll)(W/A) * (ll)(H/A);
}

int main(void){

	ll N,L,W,H;
	scanf("%lld %lld %lld %lld",&N,&L,&W,&H);

	double left=0.0001, right=10000000000.0, mid;
	double oldLeft=-1, oldRight=-1;
	double ans=0;

	while(fabs(oldLeft-left)>1e-9 || fabs(oldRight-right)>1e-9){
		mid=(left+right)*0.5;
		ll curBox = maxBox(mid,L,W,H);

		oldLeft=left, oldRight=right;

		if(curBox>=N){
			if(ans<mid) ans=mid;
			left=mid;
		}
		else right=mid;
	}
	printf("%.10lf\n",ans);
	return 0;
}
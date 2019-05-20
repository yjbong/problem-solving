#include <cstdio>
int T,d;
int main(void){
	scanf("%d\n",&T);
	while(T--){
		scanf("%d",&d);
		// binary search
		int left=0, right=d;
		int ans=0;
		while(left<=right){
			int mid=(left+right)/2;
			if(mid+mid*mid<=d){
				if(ans<mid) ans=mid;
				left=mid+1;
			}
			else right=mid-1;
		}
	    printf("%d\n",ans);
	}
	return 0;
}
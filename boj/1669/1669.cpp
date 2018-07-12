#include <cstdio>
#include <cmath>
int main(void){
	int X,Y;
	scanf("%d %d",&X,&Y);
	int gap=Y-X;
	int ans;
	if(gap==0) ans=0;
	else{
		int sqrtGap=(int)sqrt(gap);
		ans=sqrtGap*2-1;
		int remain=gap-sqrtGap*sqrtGap;
		if(remain==0);
		else if(remain<=sqrtGap) ans++;
		else ans+=2;
	}
	printf("%d\n",ans);
	return 0;
}
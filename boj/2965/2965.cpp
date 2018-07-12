#include <cstdio>
int max2(int a, int b){ return a>b?a:b; }
int main(void){
	int A,B,C;
	scanf("%d %d %d",&A,&B,&C);
	int ans=max2(B-A-1,C-B-1);
	printf("%d\n",ans);
	return 0;
}
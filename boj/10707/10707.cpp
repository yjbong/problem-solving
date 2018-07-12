#include <cstdio>
int min2(int a, int b){ return a<b?a:b; }
int main(void){
	int a,b,c,d,p;
	scanf("%d %d %d %d %d",&a,&b,&c,&d,&p);
	int ans=min2(a*p,b+(p<=c?0:(p-c)*d));
	printf("%d\n",ans);
	return 0;
}
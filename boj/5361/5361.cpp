#include <cstdio>
int main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		int a,b,c,d,e;
		scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
		double ans=350.34*a+230.90*b+190.55*c+125.30*d+180.90*e;
		printf("$%.2lf\n",ans);
	}	
	return 0;
}
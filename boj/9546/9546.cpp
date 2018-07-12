#include <cstdio>
int main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		int k;
		scanf("%d",&k);
		double ans=0;
		for(int i=0; i<k; i++) ans=(ans+0.5)*2;
		printf("%.0lf\n",ans);
	}
	return 0;
}
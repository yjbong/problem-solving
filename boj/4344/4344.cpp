#include <cstdio>
int pnt[1000];
int main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int sum=0;
		for(int i=0; i<n; i++){
			scanf("%d",&pnt[i]);
			sum+=pnt[i];
		}
		double avg=(double)sum/n;

		int m=0;
		for(int i=0; i<n; i++) if(pnt[i]>avg) m++;
		printf("%.3lf%%\n",m*100.0/n);
	}
	return 0;
}
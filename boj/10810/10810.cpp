#include <cstdio>
int n,m;
int a[101];
int main(void){
	scanf("%d %d",&n,&m);
	for(int i=0; i<m; i++){
		int from,to,num;
		scanf("%d %d %d",&from,&to,&num);
		for(int j=from; j<=to; j++) a[j]=num;
	}
	for(int i=1; i<=n; i++) printf("%d ",a[i]);
	printf("\n");
	return 0;
}
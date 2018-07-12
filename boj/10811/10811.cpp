#include <cstdio>
int n,m;
int a[101];
int main(void){
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++) a[i]=i;
	for(int i=0; i<m; i++){
		int from,to,num;
		scanf("%d %d",&from,&to);
		for(int j=from; j<=(from+to)/2; j++){
			int tmp;
			tmp=a[j];
			a[j]=a[to-(j-from)];
			a[to-(j-from)]=tmp;
		}
	}
	for(int i=1; i<=n; i++) printf("%d ",a[i]);
	printf("\n");
	return 0;
}
#include <cstdio>
int a[10000];
int main(void){
	int n,x;
	scanf("%d %d",&n,&x);
	for(int i=0; i<n; i++) scanf("%d",&a[i]);
	for(int i=0; i<n; i++) if(a[i]<x) printf("%d ",a[i]);
	printf("\n");
	return 0;
}
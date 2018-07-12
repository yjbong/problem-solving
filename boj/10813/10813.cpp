#include <cstdio>
int n; // 바구니의 수
int m; // 교환 횟수
int a[101]; // a[i] = i번 바구니에 들어있는 공의 번호
int main(void){

	scanf("%d %d",&n,&m);
	for(int t=1; t<=n; t++) a[t]=t;
	for(int t=1; t<=m; t++){
		int i,j,tmp;
		scanf("%d %d",&i,&j);
		tmp=a[i]; a[i]=a[j]; a[j]=tmp; // a[i],a[j]를 swap
	}
	for(int i=1; i<=n; i++) printf("%d ",a[i]);
	printf("\n");
	return 0;
}
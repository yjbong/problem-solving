#include <cstdio>
int main(void){
	int n;
	scanf("%d",&n);
	for(int i=1; i<=2*n-1; i++){
		int k=(i<=n)?i:2*n-i;
		for(int j=1; j<=k; j++) printf("*");
		for(int j=k+1; j<=2*n-k; j++) printf(" ");
		for(int j=2*n-k+1; j<=2*n; j++) printf("*");
		printf("\n");
	}
	return 0;
}
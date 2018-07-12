#include <cstdio>
int main(void){
	int n;
	scanf("%d",&n);
	for(int i=1; i<=2*n-1; i++){
		for(int j=1; j<=n; j++){
			if(i<=n){
				if(j<=n-i) printf(" ");
				else printf("*");
			}
			else{
				if(j<=n-(2*n-i)) printf(" ");
				else printf("*");
			}
		}
		printf("\n");
	}
	return 0;
}
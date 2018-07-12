#include <cstdio>
int main(void){
	int n;
	scanf("%d",&n);
	for(int i=1; i<=2*n-1; i++){
		int numIter=i;
		if(i>n) numIter=2*n-i;
		for(int j=0; j<numIter; j++) printf("*");
		printf("\n");
	}		
	return 0;
}
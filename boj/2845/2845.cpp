#include <cstdio>
int main(void){
	int L,P;
	scanf("%d %d",&L,&P);
	for(int i=0; i<5; i++){
		int p;
		scanf("%d",&p);
		printf("%d ",p-L*P);
	}
	printf("\n");
	return 0;
}
#include <cstdio>
int d[15][15]; // d[i][j] = i층 j호의 사람 수
int main(void){

	for(int i=1; i<=14; i++) d[0][i]=i;
	for(int i=1; i<=14; i++)
		for(int j=1; j<=14; j++)
			for(int k=1; k<=j; k++) d[i][j]+=d[i-1][k];

	int t;
	scanf("%d",&t);
	while(t--){
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d\n",d[a][b]);
	}
	return 0;
}
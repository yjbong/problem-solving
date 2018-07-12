#include <cstdio>
int d[11][11]; // d[i][j] = iCj
int n,k;
int main(void){
	scanf("%d %d",&n,&k);
	for(int i=0; i<=n; i++) d[i][0]=1;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=i; j++) d[i][j]=d[i-1][j]+d[i-1][j-1];
	printf("%d\n",d[n][k]);
	return 0;
}
#include <cstdio>
int d[1001][10]; // d[i][j] = 길이가 i이고 마지막 자리가 j인 오르막 수의 개수
int n;
int main(void){
	// base case
	scanf("%d",&n);
	for(int j=0; j<=9; j++) d[1][j]=1;
	for(int i=1; i<=n; i++)
		for(int j=0; j<=9; j++)
			for(int k=0; k<=j; k++) d[i][j]=(d[i][j]+d[i-1][k])%10007;

	int ans=0;
	for(int j=0; j<=9; j++)
		ans=(ans+d[n][j])%10007;
	printf("%d\n",ans);
	return 0;
}
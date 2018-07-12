#include <cstdio>
int d[101][10]; // d[i][j]=i자리 수이고, 숫자 j로 끝나는 계단수의 개수
int N;
int main(void){
	for(int j=1; j<=9; j++) d[1][j]=1; // 0으로 시작하는 수는 없다
	scanf("%d",&N);
	for(int i=2; i<=N; i++){
		for(int j=0; j<=9; j++){
			if(j-1>=0) d[i][j]=(d[i][j]+d[i-1][j-1])%1000000000;
			if(j+1<=9) d[i][j]=(d[i][j]+d[i-1][j+1])%1000000000;
		}
	}
	int ans=0;
	for(int j=0; j<=9; j++) ans=(ans+d[N][j])%1000000000;
	printf("%d\n",ans);
	return 0;
}
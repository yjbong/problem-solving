#include <cstdio>
typedef long long ll;
int N; // 수열의 길이
int K; // 타겟 k값
int A0; // A[0] 값
ll d[20][20][20][20]; // d[i][j][k] = 수 0,1,2,...,i+j 로 이루어진 수열에서 0의 왼쪽에 i개의 수가 있고 오른쪽에 j개의 수가 있을 때,
		      // 0의 왼쪽에서 일어난 역전이 k개이고 0의 오른쪽에서 일어난 역전이 l개 일 때의 수열의 갯수

int main(void){
	scanf("%d %d %d",&N,&K,&A0);

	// DP
	d[0][0][0][0]=1; // Base case

	for(int i=0; i<N; i++)
	for(int j=0; j<N; j++)
	for(int k=0; k<=i; k++)
	for(int l=0; l<=j; l++){
		if(i>0 && k>0) d[i][j][k][l] += (i-k+1)*d[i-1][j][k-1][l];
		if(i>0) d[i][j][k][l] += k*d[i-1][j][k][l];
		if(j>0 && l>0) d[i][j][k][l] += (j-l)*d[i][j-1][k][l-1];
		if(j>0) d[i][j][k][l] += (l+1)*d[i][j-1][k][l];
	}

	// 답 구하기
	ll ans=0;
	for(int k=0; k<N; k++)
		ans+=d[A0][N-1-A0][k][K-k];
	printf("%lld\n",ans);

	return 0;
}
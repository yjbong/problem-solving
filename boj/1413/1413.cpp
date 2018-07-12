#include <cstdio>
typedef long long ll;

int N; // 박스와 열쇠의 개수
int M; // 폭탄의 개수
ll D[21][21]; // D[i][j] = 박스와 열쇠 i쌍이 있을 때, 폭탄 j개로 i개의 열쇠를 얻을 수 있는 경우의 수 (--> 부호없는 제1종 스털링 수 = c(i,j)에 해당)
ll F[21]; // F[i] = F!
ll gcd(ll a, ll b){ return (b==0)?a:gcd(b,a%b); }

int main(void){

	scanf("%d %d",&N,&M);

	// 부호없는 제1종 스털링 수 계산
	D[0][0]=1;
	for(ll i=1; i<=N; i++) D[i][0]=0;
	for(ll j=1; j<=M; j++) D[0][j]=0;
	for(ll i=1; i<=N; i++)
		for(ll j=1; j<=M; j++)
			D[i][j]=(i-1)*D[i-1][j]+D[i-1][j-1];

	// 팩토리얼값 계산
	F[0]=1;
	for(ll i=1; i<=N; i++) F[i]=F[i-1]*i;

	// sum = 폭탄이 M개 있을 때 모든 열쇠를 얻을 수 있는 순열의 가짓수
	ll sum=0;
	for(ll i=0; i<=M; i++) sum+=D[N][i];

	// 답
	printf("%lld/%lld\n", sum/gcd(sum, F[N]), F[N]/gcd(sum, F[N]));
	return 0;
}
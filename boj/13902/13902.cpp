#include <cstdio>
#define INF 1000000000
int N; // 주문받은 짜장면의 개수
int M; // 가지고 있는 웍의 개수
int D[10001]; // D[i] = 짜장면 i그릇을 만들기 위해 필요한 최소 요리 횟수
int W[1000]; // W[i] = i번 웍으로 만들 수 있는 짜장면의 개수
bool P[10001]; // P[i] = 1번의 요리로 짜장면 i그릇을 만들 수 있는지 여부

int min2(int a, int b){ return a<b?a:b; }
int main(void){

	scanf("%d %d",&N,&M);
	for(int i=0; i<M; i++) scanf("%d",&W[i]);

	// 한번에 웍 1개로 짜장면 요리
	for(int i=0; i<M; i++) P[W[i]]=true;

	// 한번에 웍 2개로 짜장면 요리
	for(int i=0; i<M; i++)
		for(int j=i+1; j<M; j++)
			if(W[i]+W[j]<=N) P[W[i]+W[j]]=true;

	// D 배열 초기화
	for(int i=0; i<=N; i++) D[i]=INF;

	// DP
	D[0]=0; // base case
	for(int i=1; i<=N; i++)
		for(int j=1; j<=i; j++)
			if(P[j]) D[i]=min2(D[i],D[i-j]+1);

	if(D[N]<INF) printf("%d\n", D[N]);
	else printf("-1\n");
	return 0;
}
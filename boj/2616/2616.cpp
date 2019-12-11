#include <cstdio>
#define MAX_N 50000
int N; // 객차의 수 (객차는 순서대로 1, 2, ..., N번까지 있음)
int A[MAX_N+1]; // A[i] = i번 객차에 탄 승객의 수
int K; // 소형기관차 1대가 운송할 수 있는 최대 객차의 수
int S[MAX_N+1]; // S[i] =A[1]+A[2]+...+A[i]
int D[MAX_N+1][4]; // D[i][j] = i~N번 객차가 있을 때, j개의 소형기관차를 써서 운송 가능한 최대 승객 수
int min2(int a,int b){ return a<b?a:b; }
int max2(int a,int b){ return a>b?a:b; }

int solve(int idx, int numTrains){
    if(D[idx][numTrains]>=0) return D[idx][numTrains];
    if(idx>N) return 0;
    if(numTrains==0) return 0;

    int ret=0;
    // Case 1: idx번 객차를 운송하지 않고 지나감
    ret=max2(ret,solve(idx+1, numTrains));
    // Case 2: idx번 객차부터 K개(A[idx~idx+K-1])를 소형기관차 1대로 운송
    ret=max2(ret,solve(idx+K, numTrains-1)+S[idx+K-1]-S[idx-1]);

    return D[idx][numTrains]=ret;
}
int main() {
    scanf("%d",&N);
    for(int i=1; i<=N; i++) scanf("%d",&A[i]);
    for(int i=1; i<=N; i++) S[i]=S[i-1]+A[i];
    scanf("%d",&K);

    for(int i=0; i<=N; i++)
        for(int j=0; j<=3; j++)
            D[i][j]=-1;

    printf("%d\n",solve(1,3));
	return 0;
}
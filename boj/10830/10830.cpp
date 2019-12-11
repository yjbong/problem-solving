#include <cstdio>
#define MAX_N 5
 
// N*N 행렬 A,B,C에 대해, C=(A*B) mod 1000
void matMul(int N, int C[][MAX_N], int A[][MAX_N], int B[][MAX_N]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            C[i][j]=0;
            for(int k=0; k<N; k++)
                C[i][j]=(C[i][j]+A[i][k]*B[k][j])%1000;
        }
    }
}
// N*N 행렬 A에 대해, A=I
void initMat(int N, int A[][MAX_N]){
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            A[i][j]=(i==j?1:0);
}
// N*N 행렬 A,B에 대해, B=A
void copyMat(int N, int B[][MAX_N], int A[][MAX_N]){
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            B[i][j]=A[i][j];
}
void printMat(int N, int A[][MAX_N]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            printf("%d ",A[i][j]);
        printf("\n");
    }
}
 
int P[38][MAX_N][MAX_N]; // P[i]=A의 (2^i)제곱
int A[MAX_N][MAX_N];
int N;
long long B;
int ans[MAX_N][MAX_N];
int tmp[MAX_N][MAX_N];
int main() {
    scanf("%d %lld",&N,&B);
 
    // P[0](=A) 입력
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%d", &P[0][i][j]);
 
    // P 계산
    for(int i=1; i<38; i++)
        matMul(N, P[i], P[i-1], P[i-1]);
 
    // A의 B제곱 계산
    initMat(N, ans);
    for(long long i=0; i<38; i++){
        copyMat(N, tmp, ans);
        if(B&(1ll<<i)) matMul(N, ans, tmp, P[i]);
    }
    printMat(N, ans);
    return 0;
}
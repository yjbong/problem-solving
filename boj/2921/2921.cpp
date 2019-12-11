#include <cstdio>
#define MAX_N 1000
int N; // 도미노 세트의 크기
int D[MAX_N+1]; // D[i]=크기가 i인 도미노 세트에 찍힌 점의 수
int main() {
    scanf("%d",&N);
    D[0]=0;
    for(int i=1; i<=N; i++)
        D[i]=D[i-1]+i*(i+1)*3/2;
    printf("%d\n",D[N]);
    return 0;
}
#include <cstdio>
#define MAX_N 100
#define MAX_K 100000
int N; // 물품의 수
int K; // 버틸 수 있는 무게
int W[MAX_N]; // W[i] = i번 물건의 무게
int V[MAX_N]; // V[i] = i번 물건의 가치
int cache[MAX_N][MAX_K+1];

int max2(int a, int b){ return a>b?a:b; }
// solve(idx, capacity) = idx ~ N-1번 물건이 있을 때, capacity만큼 담을 수 있는 배낭에 담을 수 있는 최대 가치 합
int solve(int idx, int capacity){
    if(idx>=N) return 0;
    if(cache[idx][capacity]>=0) return cache[idx][capacity];

    int ret=0;
    // case 1: idx번 물건 선택
    if(capacity>=W[idx]) ret=max2(ret, V[idx]+solve(idx+1, capacity-W[idx]));
    // case 2: idx번 물건 미선택
    ret=max2(ret, solve(idx+1, capacity));

    return cache[idx][capacity]=ret;
}
int main() {
    scanf("%d %d",&N,&K);
    for(int i=0; i<N; i++) scanf("%d %d",&W[i],&V[i]);

    for(int i=0; i<N; i++)
        for(int j=0; j<=K; j++) cache[i][j]=-1;
    printf("%d\n",solve(0,K));
    return 0;
}
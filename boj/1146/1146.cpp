#include <cstdio>
#define MAXN 100
#define MOD 1000000

int N;

// D[i][j][0]: 마지막에 배치한 수보다 작은 수가 i개, 큰 수가 j개 있으며 이번에 마지막 수보다 작은 수를 놓아야 할 때, 앞으로 가능한 배치의 경우의 수
// D[i][j][1]: 마지막에 배치한 수보다 작은 수가 i개, 큰 수가 j개 있으며 이번에 마지막 수보다 큰 수를 놓아야 할 때, 앞으로 가능한 배치의 경우의 수
int D[MAXN+1][MAXN+1][2];

int solve(int left, int right, int up){
    int ret=0;
    if(left==0 && right==0) return 1;
    if(D[left][right][up]>=0) return D[left][right][up];

    if(up){
        if(right<=0) return 0;
        for(int i=0; i<right; i++) // 남은 수들 중, 마지막으로 배치한 수보다 큰 수들에서 마지막 수와 가까운 순서대로 선택
            ret=(ret+solve(left+i, right-1-i, 1-up))%MOD;
    }
    else{
        if(left<=0) return 0;
        for(int i=0; i<left; i++) // 남은 수들 중, 마지막으로 배치한 수보다 작은 수들에서 마지막 수와 가까운 순서대로 선택
            ret=(ret+solve(left-1-i, right+i, 1-up))%MOD;
    }
    return D[left][right][up]=ret;
}

int main() {
    scanf("%d",&N);
    if(N<=2){
        printf("%d\n",N);
        return 0;
    }

    for(int i=0; i<=N; i++)
        for(int j=0; j<=N; j++)
            D[i][j][0]=D[i][j][1]=-1;

    int ans=0;
    // i,j: 임의로 고른 첫번째, 두번째 사람의 번호(0번부터 N-1번까지로 가정)
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i==j) continue;
            else if(i<j) ans=(ans+solve(j-1, N-1-j, 0))%MOD;
            else ans=(ans+solve(j, N-2-j, 1))%MOD;
        }
    }
    printf("%d\n",ans);
    return 0;
}
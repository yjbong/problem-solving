#include <cstdio>
int n;
int s[300]; // s[i] = i번 계단의 점수
int d[300][2]; // d[i][j] = i번 계단을 마지막으로 밟았고, i번을 포함하여 연속으로 j+1개의 계단을 밟았을 때의 최대 점수

int max2(int a,int b){
    return a>b?a:b;
}
int main (void){
    scanf("%d",&n);
    for (int i=0; i<n; i++) scanf("%d",&s[i]);
    // DP
    d[0][0]=s[0];
    d[0][1]=-1000000000;
    if (n>1){
        d[1][0]=s[1];
        d[1][1]=s[0]+s[1];
    }
    for (int i=2; i<n; i++){
        d[i][0]=max2(d[i-2][0],d[i-2][1])+s[i];
        d[i][1]=d[i-1][0]+s[i];
    }
    // 답 출력
    int ans=max2(d[n-1][0],d[n-1][1]);
    printf ("%d\n",ans);
    return 0;
}
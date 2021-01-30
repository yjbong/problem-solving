#include <cstdio>
int T;
int W;
int fall[1001]; // fall[i] : i초에 떨어지는 위치 (1초부터 시작)
 
int D[1001][31][2];
int max2(int a, int b){ return a>b?a:b; }
 
// solve(time, moves, pos)현재 시각이 time이고 남은 이동횟수가 moves, 현재 위치는 pos(0또는 1)일 때 최대로 먹을 수 있는 자두의 개수
int solve(int time, int moves, int pos){
    int ret=0;
    if(time==T) return 0;
    if(D[time][moves][pos]>=0) return D[time][moves][pos];
    if(moves>0){
        ret=max2(ret, solve(time+1, moves-1, 1-pos)+(fall[time+1]==1-pos?1:0));
    }
    ret=max2(ret, solve(time+1, moves, pos)+(fall[time+1]==pos?1:0));
    return D[time][moves][pos]=ret;
}
 
int main() {
    scanf("%d %d",&T,&W);
    for(int i=1; i<=T; i++){
        scanf("%d",&fall[i]);
        fall[i]--;
    }
    for(int i=0; i<=T; i++)
        for(int j=0; j<=W; j++)
            D[i][j][0]=D[i][j][1]=-1;
    int ans=solve(0,W,0);
    printf("%d\n",ans);
    return 0;
}
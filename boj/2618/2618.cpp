#include <cstdio>
#include <cstdlib>
#define MAX_N 1000
#define MAX_W 1000
int min2(int a, int b){ return a<b?a:b; }
int N; // 동서방향 도로의 개수
int W; // 사건의 개수 (1,2,...,W번 사건)
int X[MAX_W+1], Y[MAX_W+1]; // X[i],Y[i] = i번 사건 장소
 
// solve(idx, otherpos, 0) = idx~W번 사건이 남아 있을 때 최근 사건(idx-1번 사건)은 1번 경찰차가 처리한 것이며 그 때 2번 경찰차는 otherpos번 사건 현장에 있을 때 두 경찰차가 남은 사건들을 해결하기 위해 이동해야 하는 거리의 합의 최소값
// solve(idx, otherpos, 1) = idx~W번 사건이 남아 있을 때 최근 사건(idx-1번 사건)은 2번 경찰차가 처리한 것이며 그 때 1번 경찰차는 otherpos번 사건 현장에 있을 때 두 경찰차가 남은 사건들을 해결하기 위해 이동해야 하는 거리의 합의 최소값
 
int cache[MAX_W+1][MAX_W+1][2];
int trace[MAX_W+1][MAX_W+1][2];
int solve(int idx, int otherpos, int flag){
    if(idx>W) return 0;
    if(cache[idx][otherpos][flag]>=0) return cache[idx][otherpos][flag];
 
    int ret=2000000000;
    int p1x, p1y, p2x, p2y;
    if(flag==0){
        // 두 경찰차의 위치 확인
        if(idx-1==0){ p1x=p1y=1; }
        else{ p1x=X[idx-1]; p1y=Y[idx-1]; }
        if(otherpos==0){ p2x=p2y=N; }
        else{ p2x=X[otherpos]; p2y=Y[otherpos]; }
 
        // case 1: 1번 경찰차가 idx번 사건 장소로 이동
        int val1=abs(X[idx]-p1x)+abs(Y[idx]-p1y)+solve(idx+1, otherpos, flag);
        if(ret>val1){ ret=val1; trace[idx][otherpos][flag]=1; }
 
        // case 2: 2번 경찰차가 idx번 사건 장소로 이동
        int val2=abs(X[idx]-p2x)+abs(Y[idx]-p2y)+solve(idx+1, idx-1, 1-flag);
        if(ret>val2){ ret=val2; trace[idx][otherpos][flag]=2; }
    }
    else{
        // 두 경찰차의 위치 확인
        if(idx-1==0){ p2x=p2y=N; }
        else{ p2x=X[idx-1]; p2y=Y[idx-1]; }
        if(otherpos==0){ p1x=p1y=1; }
        else{ p1x=X[otherpos]; p1y=Y[otherpos]; }
 
        // case 1: 1번 경찰차가 idx번 사건 장소로 이동
        int val1=abs(X[idx]-p1x)+abs(Y[idx]-p1y)+solve(idx+1, idx-1, 1-flag);
        if(ret>val1){ ret=val1; trace[idx][otherpos][flag]=1; }
 
        // case 2: 2번 경찰차가 idx번 사건 장소로 이동
        int val2=abs(X[idx]-p2x)+abs(Y[idx]-p2y)+solve(idx+1, otherpos, flag);
        if(ret>val2){ ret=val2; trace[idx][otherpos][flag]=2; }
    }
    return cache[idx][otherpos][flag]=ret;
}
 
int main(){
    // 입력
    scanf("%d",&N);
    scanf("%d",&W);
    for(int i=1; i<=W; i++) scanf("%d %d",&X[i],&Y[i]);
 
    // cache 초기화
    for(int i=0; i<=W; i++)
        for(int j=0; j<=W; j++)
            cache[i][j][0]=cache[i][j][1]=-1;
 
    // 최소 이동 거리 출력
    printf("%d\n", solve(1,0,0));
 
    // 사건 할당 결과 출력
    int curOtherpos=0, curFlag=0;
    for(int idx=1; idx<=W; idx++){
        printf("%d\n",trace[idx][curOtherpos][curFlag]);
        if(curFlag==0 && trace[idx][curOtherpos][curFlag]==2){
            curOtherpos=idx-1;
            curFlag=1-curFlag;
        }
        if(curFlag==1 && trace[idx][curOtherpos][curFlag]==1){
            curOtherpos=idx-1;
            curFlag=1-curFlag;
        }
    }
    return 0;
}
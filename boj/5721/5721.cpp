#include <cstdio>
int max2(int a, int b){ return a>b?a:b; }
int N,M;
int A[100000];
int D[100000]; // D[i] = 현재 row에서 마지막에 고른 사탕의 col 위치가 i일 때 가능한 최대 사탕의 수
int cache[100000];
int solve(int lastRow){
 
    if(cache[lastRow]>=0) return cache[lastRow];
 
    int lastRowMax=0; // 현재 행에서 얻을 수 있는 사탕의 최대값
    for(int i=0; i<N; i++){
        D[i]=A[lastRow*N+i];
        int before=0;
        if(i>=2) before=max2(before,D[i-2]);
        if(i>=3) before=max2(before,D[i-3]);
        D[i]+=before;
    }
    if(N>=1) lastRowMax=max2(lastRowMax,D[N-1]);
    if(N>=2) lastRowMax=max2(lastRowMax,D[N-2]);
 
    int remainRowsMax=0; // 현재 행보다 아래쪽에서 얻을 수 있는 사탕의 최대값
    if(lastRow+2<M) 
 remainRowsMax=max2(remainRowsMax,solve(lastRow+2));
    if(lastRow+3<M) 
 remainRowsMax=max2(remainRowsMax,solve(lastRow+3));
 
    return cache[lastRow]=lastRowMax+remainRowsMax;
}
int main() {
    while(1){
        scanf("%d %d",&M,&N);
        if(M==0 && N==0) break;
        for(int i=0; i<M; i++)
            for(int j=0; j<N; j++) scanf("%d",&A[i*N+j]);
 
        for(int i=0; i<M; i++) cache[i]=-1;
        int ans=0;
        if(M>0) ans=max2(ans,solve(0));
        if(M>1) ans=max2(ans,solve(1));
        printf("%d\n",ans);
    }
    return 0;
}
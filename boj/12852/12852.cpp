#include <cstdio>
#define MAX_N 1000000
int N;
int D[MAX_N+1]; // D[i] = i를 1로 만들기 위해 필요한 최소 연산 횟수
int T[MAX_N+1];
int go(int n){
    if(D[n]>=0) return D[n];
    if(n==1) return D[n]=0;
 
    int ret=1000000000;
    if(n%3==0){
        if(ret>go(n/3)) { ret=go(n/3)+1; T[n]=n/3; }
    }
    if(n%2==0){
        if(ret>go(n/2)) { ret=go(n/2)+1; T[n]=n/2; }
    }
    if(ret>go(n-1)) { ret=go(n-1)+1; T[n]=n-1; }
 
    return D[n]=ret;
}
int main() {
 
    scanf("%d",&N);
    for(int i=0; i<=N; i++){ D[i]=-1; T[i]=0; }
    printf("%d\n",go(N));
    int trace=N;
    while(trace>0){
        printf("%d ",trace);
        trace=T[trace];
    }
    printf("\n");
    return 0;
}
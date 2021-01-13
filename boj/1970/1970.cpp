#include <cstdio>
#define MAXN 1000
int N;
int A[MAXN]; // A[i]=i번 사람의 콜라 브랜드
int D[MAXN][MAXN]; // D[i][j]=A[i~j]에서의 최대 악수 쌍
int max2(int a, int b){ return a>b?a:b; }

int main() {
    scanf("%d",&N);
    for(int i=0; i<N; i++) scanf("%d",&A[i]);

    for(int i=0; i<N; i++){ // 여기서 i는 구간의 크기-1
        for(int j=0; j<N; j++){ // j는 구간의 시작 idx
            int st=j, ed=(j+i)%N;
            if(i==0){ // 구간에 속한 사람이 1명
                D[st][ed]=0;
            }
            else if(i==1){ // 2명
                if(A[st]==A[ed]) D[st][ed]=1;
            }
            else{
                D[st][ed]=max2(D[st][ed], D[(st+1)%N][(ed+N-1)%N]+(A[st]==A[ed]?1:0));
                for(int k=st; k<ed; k=(k+1)%N)
                    D[st][ed]=max2(D[st][ed], D[st][k]+D[(k+1)%N][ed]);
            }
        }
    }
    int ans=0;
    for(int i=0; i<N; i++){
        int st=i, ed=(i+N-1)%N;
        ans=max2(ans,D[st][ed]);
    }
    printf("%d\n",ans);
    return 0;
}
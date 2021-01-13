#include <cstdio>
#define MAXN 10
#define MAXD 5
 
using namespace std;
typedef long long ll;
int N; // 정점의 개수
int S,E; // 시작점과 끝점의 위치
int T; // 드라이브 시간
int G[MAXN][MAXN]; // 원본 인접 행렬 그래프
 
int newN; // 변형된 그래프에서 정점의 개수
ll newG[MAXN+MAXN*(MAXD-1)][MAXN+MAXN*(MAXD-1)]; // 변형된 그래프
ll newGPow[31][MAXN+MAXN*(MAXD-1)][MAXN+MAXN*(MAXD-1)]; // newGPow[i] = newG를 (2^i)번 곱한 그래프
 
ll ansG[MAXN+MAXN*(MAXD-1)][MAXN+MAXN*(MAXD-1)];
ll tmpG[MAXN+MAXN*(MAXD-1)][MAXN+MAXN*(MAXD-1)];
 
int main() {
    scanf("%d %d %d %d",&N,&S,&E,&T);
    S--,E--; // 정점 번호는 0부터 시작하는 것으로 한다.
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++) scanf("%1d",&G[i][j]);
 
    //// newG의 가상 정점 구성
    // 0~N-1: 실제 정점
    // N+i*4+0: 실제 i번 정점에서 거리가 1인 가상 정점 (t1)
    // N+i*4+1: 실제 i번 정점에서 거리가 2인 가상 정점 (t2)
    // N+i*4+2: 실제 i번 정점에서 거리가 3인 가상 정점 (t3)
    // N+i*4+3: 실제 i번 정점에서 거리가 4인 가상 정점 (t4)
    for(int i=0; i<N; i++){
        newG[i][N+i*4+0]=1; // i->t1
        newG[N+i*4+0][N+i*4+1]=1; // t1->t2
        newG[N+i*4+1][N+i*4+2]=1; // t2->t3
        newG[N+i*4+2][N+i*4+3]=1; // t3->t4
    }
 
    //// 원본 그래프 G로부터 간선 가중치가 모두 1로 변형된 그래프 newG를 생성
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(G[i][j]>1) newG[N+i*4+G[i][j]-2][j]=1; // 가상 정점과 도착점을 연결
            else newG[i][j]=G[i][j];
        }
    }
    newN=N+N*(MAXD-1);
 
    //// newGPow 계산
    //newGPow[0]
    for(int i=0; i<newN; i++)
        for(int j=0; j<newN; j++) newGPow[0][i][j]=newG[i][j];
    for(int p=1; p<=30; p++){
        for(int i=0; i<newN; i++){
            for(int j=0; j<newN; j++){
                newGPow[p][i][j]=0;
                for(int k=0; k<newN; k++)
                    newGPow[p][i][j]=(newGPow[p][i][j]+newGPow[p-1][i][k]*newGPow[p-1][k][j])%1000003ll;
            }
        }
    }
 
    //// ansG(=T분 이후 결과 그래프) 계산
    // ansG=I 로 초기화
    for(int i=0; i<newN; i++) ansG[i][i]=1;
    // T를 반영
    for(int p=0; p<=30; p++){
        if(T&(1<<p)){
            for(int i=0; i<newN; i++)
                for(int j=0; j<newN; j++) tmpG[i][j]=ansG[i][j];
            for(int i=0; i<newN; i++){
                for(int j=0; j<newN; j++){
                    ansG[i][j]=0;
                    for(int k=0; k<newN; k++)
                        ansG[i][j]=(ansG[i][j]+tmpG[i][k]*newGPow[p][k][j])%1000003ll;
                }
            }
        }
    }
 
    ll ans=ansG[S][E];
    printf("%lld\n",ans);
    return 0;
}
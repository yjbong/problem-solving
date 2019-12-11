#include <cstdio>
#include <queue>
#define MAX_N 20
#define INF 1000000000
using namespace std;
typedef pair <int, int> ii;
 
int N; // 공간의 크기
int A[MAX_N][MAX_N]; // A[i][j]=현재 (i,j)의 상태
int dist[MAX_N][MAX_N]; // dist[i][j]=상어의 현재 위치에서 (i,j)로 이동하는데 드는 최소 거리
int sharkY, sharkX; // 상어의 위치
 
queue <ii> q;
const int dy[4]={1,-1,0,0};
const int dx[4]={0,0,-1,1};
 
int main() {
    scanf("%d",&N);
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%d",&A[i][j]);
 
    // 상어의 초기 위치 확인
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(A[i][j]==9){
                sharkY=i;
                sharkX=j;
            }
        }
    }
 
    // 상어의 크기, 상어가 먹은 물고기의 수
    int curSize = 2;
    int curEat = 0;
 
    int ans=0;
    while(1){
        // dist 초기화
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++) dist[i][j]=INF;
 
        // BFS
        dist[sharkY][sharkX]=0;
        q.push(make_pair(sharkY,sharkX));
 
        int targetY=-1, targetX=-1, targetDist=INF;
        while(!q.empty()){
            ii f=q.front(); q.pop();
            int fy=f.first, fx=f.second;
            if(targetDist<=dist[fy][fx]) continue;
 
            for(int k=0; k<4; k++){
                int cy=fy+dy[k], cx=fx+dx[k];
                if(cy<0 || cy>=N || cx<0 || cx>=N) continue;
                if(dist[cy][cx]>dist[fy][fx]+1 && A[cy][cx]<=curSize){
                    dist[cy][cx]=dist[fy][fx]+1;
                    q.push(make_pair(cy,cx));
                    if(A[cy][cx]>0 && A[cy][cx]!=9 && A[cy][cx]<curSize){
                        bool update=false;
                        if(targetDist>dist[cy][cx]) update=true;
                        else if(targetDist==dist[cy][cx]){
                            if(cy<targetY) update=true;
                            else if(cy==targetY && cx<targetX) update=true;
                        }
                        if(update){
                            targetY=cy, targetX=cx, targetDist=dist[cy][cx];
                        }
                    }
                }
            }
        }
 
        // 먹을 수 있는 물고기가 없는 경우
        if(targetDist>=INF) break;
 
        // 가장 가까운 먹이의 위치로 이동
        ans+=targetDist;
        A[sharkY][sharkX]=0;
        sharkY=targetY, sharkX=targetX;
        A[sharkY][sharkX]=9;
        curEat++;
        if(curEat==curSize){
            curEat=0;
            curSize++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
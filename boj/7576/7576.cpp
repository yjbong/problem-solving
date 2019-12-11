#include <cstdio>
#include <queue>
#include <utility>
#define INF 1000000000
#define MAX_M 1000
#define MAX_N 1000

using namespace std;
typedef pair<int, int> ii;

const int dx[4]={+1,-1, 0, 0};
const int dy[4]={ 0, 0,+1,-1};
int M,N; // 상자의 가로,세로
int A[MAX_N][MAX_M]; // 정수 1은 익은 토마토, 정수 0 은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸
int day[MAX_N][MAX_M]; // day[i][j] = i,j,k에 익지 않은 토마토가 있다면, 익는데 걸리는 day 수
queue <ii> q;

int main() {
    scanf("%d %d",&M,&N);
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            scanf("%d",&A[i][j]);

    // day 초기화
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++){
            if(A[i][j]==0) day[i][j]=INF;
            else if(A[i][j]==1) q.push(make_pair(i,j));
        }

    // BFS
    while(!q.empty()){
        ii f=q.front(); q.pop();
        int fy=f.first;
        int fx=f.second;

        for(int i=0; i<4; i++){
            int cy=fy+dy[i];
            int cx=fx+dx[i];
            if(cy<0 || cy>=N || cx<0 || cx>=M) continue;
            if(A[cy][cx]==0 && day[cy][cx]>day[fy][fx]+1){
                day[cy][cx]=day[fy][fx]+1;
                q.push(make_pair(cy,cx));
            }
        }
    }

    // ans
    int ans=0;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            if(ans<day[i][j]) ans=day[i][j];
    if(ans<INF) printf("%d\n",ans);
    else printf("-1\n");
    return 0;
}
#include <cstdio>
#include <queue>
#include <utility>
#define INF 1000000000
#define MAX_M 100
#define MAX_N 100
#define MAX_H 100
 
using namespace std;
typedef pair<int, pair<int, int> > iii;
 
const int dx[6]={+1,-1, 0, 0, 0, 0};
const int dy[6]={ 0, 0,+1,-1, 0, 0};
const int dz[6]={ 0, 0, 0, 0,+1,-1};
int M,N,H; // 상자의 가로,세로,높이
int A[MAX_H][MAX_N][MAX_M]; // 정수 1은 익은 토마토, 정수 0 은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸
int day[MAX_H][MAX_N][MAX_M]; // day[i][j][k] = i,j,k에 익지 않은 토마토가 있다면, 익는데 걸리는 day 수
queue <iii> q;
 
int main() {
    scanf("%d %d %d",&M,&N,&H);
    for(int i=0; i<H; i++)
        for(int j=0; j<N; j++)
            for(int k=0; k<M; k++)
                scanf("%d",&A[i][j][k]);
 
    // day 초기화
    for(int i=0; i<H; i++)
        for(int j=0; j<N; j++)
            for(int k=0; k<M; k++){
                if(A[i][j][k]==0) day[i][j][k]=INF;
                else if(A[i][j][k]==1) q.push(make_pair(i,make_pair(j,k)));
            }
 
    // BFS
    while(!q.empty()){
        iii f=q.front(); q.pop();
        int fz=f.first;
        int fy=f.second.first;
        int fx=f.second.second;
 
        for(int i=0; i<6; i++){
            int cz=fz+dz[i];
            int cy=fy+dy[i];
            int cx=fx+dx[i];
            if(cz<0 || cz>=H || cy<0 || cy>=N || cx<0 || cx>=M) continue;
            if(A[cz][cy][cx]==0 && day[cz][cy][cx]>day[fz][fy][fx]+1){
                day[cz][cy][cx]=day[fz][fy][fx]+1;
                q.push(make_pair(cz, make_pair(cy,cx)));
            }
        }
    }
 
    // ans
    int ans=0;
    for(int i=0; i<H; i++)
        for(int j=0; j<N; j++)
            for(int k=0; k<M; k++)
                if(ans<day[i][j][k]) ans=day[i][j][k];
    if(ans<INF) printf("%d\n",ans);
    else printf("-1\n");
    return 0;
}
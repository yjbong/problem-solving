#include <cstdio>
#include <queue>
#include <utility>
#include <set>
#define MAX_N 2000
#define MAX_M 2000
#define DEBUG 0
using namespace std;
typedef pair<int, int> ii;
int N,M;
char input[MAX_N][MAX_M+1];
int color[MAX_N][MAX_M];
bool visited[MAX_N][MAX_M];
const int dy[4]={-1, 1, 0, 0};
const int dx[4]={0, 0, -1, 1};
const int diagy[4]={-1, -1, 1, 1};
const int diagx[4]={-1, 1, -1, 1};
queue <ii> q;
set <int> safeColorList;
 
int main() {
    // 입력
    scanf("%d %d\n",&N,&M);
	for(int i=0; i<N; i++) scanf("%s",input[i]);
#if DEBUG
    printf("%d %d\n",N,M);
    for(int i=0; i<N; i++) printf("%s\n",input[i]);
#endif
 
    // 같은 섬에 속하는 셀들을 같은 값으로 매김 (바다: 음수)
    int curColor=1;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(color[i][j]==0){
                if(input[i][j]=='.') color[i][j]=-1; // 바다: 음수
                else{
                    color[i][j]=curColor; 
                    q.push(make_pair(i,j));
                    while(!q.empty()){
                        ii f=q.front(); q.pop();
                        int fy=f.first, fx=f.second;
                        color[fy][fx]=curColor; 
                        for(int k=0; k<4; k++){
                            int cy=fy+dy[k];
                            int cx=fx+dx[k];
                            if(cy>=0 && cy<N && cx>=0 && cx<M && input[cy][cx]=='#' && color[cy][cx]==0){
                                color[cy][cx]=curColor; 
                                q.push(make_pair(cy,cx));
                            }
                        }
                    }
                    curColor++;
                }
            }
        }
    }
#if DEBUG
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(color[i][j]<0) printf(".");
            else printf("%d",color[i][j]);
        }
        printf("\n");
    }
#endif
 
    // 안전한 섬들을 확인
    q.push(make_pair(0,0)); // 임의의 경계점(무조건 바다임)부터 시작
    while(!q.empty()){
        ii f=q.front(); q.pop();
        int fy=f.first, fx=f.second;
 
        int cy, cx;
        // 상하좌우 이동
        for(int k=0; k<4; k++){
            cy=fy+dy[k];
            cx=fx+dx[k];
            if(cy>=0 && cy<N && cx>=0 && cx<M && !visited[cy][cx]){
                if(input[cy][cx]=='.') q.push(make_pair(cy,cx));
                else safeColorList.insert(color[cy][cx]); // 바다와 인접한 섬은 안전한 섬이다.
                visited[cy][cx]=true;
            }
        }
 
        // 대각선 이동
        // 대각선 이동은 이런 상황에서 고려한다. 출발지와 도착지 셀은 바다다. 출발지와 도착지 셀은 육지와 변을 공유한다. 예를 들면
        // S#
        // #D
        // 와 같은 경우이다. (S는 출발, D는 도착)
        // 이 때, 두 개의 육지 셀은 서로 다른 색으로 칠해져 있어야 한다. (그래야 두 섬 중 하나를 골라서 이동할 수 있는 것이므로)
        for(int k=0; k<4; k++){
            cy=fy+diagy[k], cx=fx+diagx[k];
            if(cy>=0 && cy<N && cx>=0 && cx<M &&
                input[cy-diagy[k]][cx]=='#' &&
                input[cy][cx-diagx[k]]=='#' &&
                input[cy][cx]=='.' &&
                color[cy-diagy[k]][cx]!=color[cy][cx-diagx[k]] &&
                !visited[cy][cx]){
                q.push(make_pair(cy,cx)); 
                visited[cy][cx]=true;
            }
        }
    }
 
    set<int>::iterator it;
#if DEBUG
    printf("safe color: ");
    for(it=safeColorList.begin(); it!=safeColorList.end(); it++)
        printf("%d ", *it);
    printf("\n");
#endif
 
    // 결과 출력
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(input[i][j]=='.') printf(".");
            else{
                it=safeColorList.find(color[i][j]);
                if(it!=safeColorList.end()) printf("O");
                else printf("X");
            }
        }
        printf("\n");
    }
    return 0;
}
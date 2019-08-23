#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#define MAX_N 700
#define MAX_M 700
#define INF 1000000000
using namespace std;
typedef pair<int,int> ii;
int N,M; // 입력되는 지도는 N행 M열
char input[MAX_N][MAX_M+10];

int viking[MAX_N][MAX_M]; // viking[i][j] = 해적이 i,j 위치로 가는데 걸리는 턴 수
int lineMin[MAX_N*MAX_M*2]; // lineMin[i] = i번 라인에 속한 모든 셀 k에 대하여 min(viking[k]). line은 수평, 수직 방향으로 벽을 만나기 전까지 연속된 셀들의 집합이다.
int lines;

vector<int> cellLine[MAX_N][MAX_M]; // cellLine[i][j] = i,j 위치를 포함하는 line 목록 (최소 1개, 최대 2개일 수 밖에 없다.)

int deadLine[MAX_N][MAX_M]; // deadLine[i][j] = i,j 위치까지 해적에게 들키지 않고 가려면 이 값보다 작은 수의 턴에 도착해야 한다.

int sua[MAX_N][MAX_M]; // sua[i][j] = 수아가 i,j 위치까지 해적에게 들키지 않고 갈 때 필요한 최소 턴 수

const int dy[4]={-1,1,0,0};
const int dx[4]={0,0,-1,1};
queue<ii> q;

int main() {
    scanf("%d %d\n",&N,&M);
    for(int i=0; i<N; i++){
        fgets(input[i], MAX_M+9, stdin);
        if(input[i][strlen(input[i])-1]=='\n') input[i][strlen(input[i])-1]=0;
    }

    //// viking 배열 구성
    int vy,vx; // 해적의 위치
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            if(input[i][j]=='V'){ vy=i, vx=j; }
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            viking[i][j]=INF;
    q.push(make_pair(vy,vx));
    viking[vy][vx]=0;
    while(!q.empty()){
        ii f=q.front(); q.pop();
        int fy=f.first, fx=f.second;
        for(int k=0; k<4; k++){
            int cy=fy+dy[k];
            int cx=fx+dx[k];
            if(cy>=0 && cy<N && cx>=0 && cx<M
                && input[cy][cx]!='I'
                && viking[cy][cx]>viking[fy][fx]+1){
                viking[cy][cx]=viking[fy][fx]+1;
                q.push(make_pair(cy,cx));
            }
        }
    }

    //// line 정보(lineMin, cellLine) 구성
    lines=0;
    // 수평 방향 line
    for(int i=0; i<N; i++){
        int curMin=INF;
        for(int j=0; j<M; j++){
            if(input[i][j]!='I'){
                if(curMin>viking[i][j]) curMin=viking[i][j];
                cellLine[i][j].push_back(lines);
            }
            if((input[i][j]=='I' || j==M-1) && curMin<INF){
                lineMin[lines++]=curMin; // 현재 line segment의 끝
                curMin=INF;
            }
        }
    }
    // 수직 방향 line
    for(int j=0; j<M; j++){
        int curMin=INF;
        for(int i=0; i<N; i++){
            if(input[i][j]!='I'){
                if(curMin>viking[i][j]) curMin=viking[i][j];
                cellLine[i][j].push_back(lines);
            }
            if(input[i][j]=='I' || i==N-1){
                lineMin[lines++]=curMin; // 현재 line segment의 끝
                curMin=INF;
            }
        }
    }

    //// deadLine 구성
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            deadLine[i][j]=INF;
            for(int k=0; k<cellLine[i][j].size(); k++)
                if(deadLine[i][j]>lineMin[cellLine[i][j][k]])
                    deadLine[i][j]=lineMin[cellLine[i][j][k]];
        }
    }

    // 보물을 얻을 수 있는지 확인
    int yy,yx; // 수아의 위치
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            if(input[i][j]=='Y'){ yy=i, yx=j; }

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            sua[i][j]=INF;

    q.push(make_pair(yy,yx));
    sua[yy][yx]=0;
    while(!q.empty()){
        ii f=q.front(); q.pop();
        int fy=f.first, fx=f.second;
        for(int k=0; k<4; k++){
            int cy=fy+dy[k];
            int cx=fx+dx[k];
            if(cy>=0 && cy<N && cx>=0 && cx<M
                && input[cy][cx]!='I'
                && sua[cy][cx]>sua[fy][fx]+1
                && deadLine[cy][cx]>sua[fy][fx]+1){ // 데드라인 이내에 도착해야 함
                sua[cy][cx]=sua[fy][fx]+1;
                q.push(make_pair(cy,cx));
            }
        }
    }

    bool ok=false;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            if(input[i][j]=='T' && sua[i][j]<INF) ok=true;

    if(ok) printf("YES\n");
    else printf("NO\n");

    return 0;
}
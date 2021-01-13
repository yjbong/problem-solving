#include <cstdio>
#include <queue>
#define MAXN 50
#define MAXM 50
#define INF 1000000000
using namespace std;
 
class Data{
public:
    int state;
    int y;
    int x;
    Data(int state, int y, int x){
        this->state=state;
        this->y=y;
        this->x=x;
    }
};
const int dy[4]={-1,1,0,0};
const int dx[4]={0,0,1,-1};
 
int N,M; // 미로의 세로, 가로 크기
char A[MAXN][MAXM+1];
int D[1<<6][MAXN][MAXM]; // D[i][j][k]=열쇠를 가진 상태가 i이면서 시작점에서 A[j][k]로의 최소 이동 횟수
queue <Data*> q;
 
int main() {
	// your code goes here
    scanf("%d %d\n",&N,&M);
    for(int i=0; i<N; i++) scanf("%s\n",A[i]);
    //printf("%d %d\n",N,M);
    //for(int i=0; i<N; i++) printf("%s\n",A[i]);
 
    for(int i=0; i<(1<<6); i++)
        for(int j=0; j<N; j++)
            for(int k=0; k<M; k++) D[i][j][k]=INF;
 
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            if(A[i][j]=='0'){ q.push(new Data(0,i,j)); D[0][i][j]=0; }
 
    while(!q.empty()){
        Data* f=q.front(); q.pop();
        int fstate=f->state, fy=f->y, fx=f->x;
        delete f;
        for(int i=0; i<4; i++){
            int cy=fy+dy[i], cx=fx+dx[i], cstate=fstate;
            // 이동 가능 체크
            if(cy<0 || cy>=N || cx<0 || cx>=M) continue;
            else if(A[cy][cx]=='#') continue;
            else if(A[cy][cx]>='A' && A[cy][cx]<='F'){
                if(!(fstate & (1<<(A[cy][cx]-'A')))) continue;
            }
            else if(A[cy][cx]>='a' && A[cy][cx]<='f')
                cstate |= (1<<(A[cy][cx]-'a'));
 
            // update
            if(D[cstate][cy][cx]>D[fstate][fy][fx]+1){
                D[cstate][cy][cx]=D[fstate][fy][fx]+1;
                q.push(new Data(cstate,cy,cx));
            }
        }
    }
    int ans=INF;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            if(A[i][j]=='1')
                for(int k=0; k<(1<<6); k++)
                    if(ans>D[k][i][j]) ans=D[k][i][j];
 
    if(ans<INF) printf("%d\n",ans);
    else printf("-1\n");
    return 0;
}
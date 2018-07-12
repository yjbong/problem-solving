#include <cstdio>
#include <queue>
#define INF 1000000000
using namespace std;
typedef pair<int,int> ii;
const int dy[4]={1,-1,0,0};
const int dx[4]={0,0,-1,1};

int b[111][111];
int s[111][111];

int main(void){

    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            scanf("%1d",&b[i][j]);

    for(int i=0; i<=n+1; i++)
        for(int j=0; j<=m+1; j++) s[i][j]=INF;
    s[1][1]=1;

    queue<ii> q;
    q.push(ii(1,1));
    while(!q.empty()){

        ii f=q.front();
        q.pop();
        int fy=f.first;
        int fx=f.second;
        for(int i=0; i<4; i++){
            int cy=fy+dy[i];
            int cx=fx+dx[i];
            if(b[cy][cx]){
                if(s[cy][cx]>s[fy][fx]+1){
                    s[cy][cx]=s[fy][fx]+1;
                    q.push(ii(cy,cx));
                }
            }
        }
    }

    printf("%d\n",s[n][m]);
    return 0;
}
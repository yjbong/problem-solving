#include <cstdio>
#include <queue>
using namespace std;
typedef pair<int,int> ii;
const int dx[4]={-1,1,0,0};
const int dy[4]={0,0,-1,1};
bool c[111][111];
int b[111][111];
int main(void){

    int n,m,k,max;
    scanf("%d %d %d",&n,&m,&k);

    for(int i=0; i<=n+1; i++){
        for(int j=0; j<=m+1; j++){
            b[i][j]=0;
            c[i][j]=false;
        }
    }
    for(int i=0; i<k; i++){
        int t1,t2;
        scanf("%d %d",&t1,&t2);
        b[t1][t2]=1;
    }

    queue<ii> q;
    max=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(!c[i][j] && b[i][j]){
                q.push(ii(i,j));
                c[i][j]=true;
                int cur=0;
                while(!q.empty()){
                    ii f=q.front();
                    q.pop();
                    cur++;
                    for(int u=0; u<4; u++){
                        int nx=f.first+dx[u];
                        int ny=f.second+dy[u];
                        if(!c[nx][ny] && b[nx][ny]){
                            q.push(ii(nx,ny));
                            c[nx][ny]=true;
                        }
                    }
                }

                if(max<cur) max=cur;
            }
        }
    }
    printf("%d\n",max);
    return 0;
}
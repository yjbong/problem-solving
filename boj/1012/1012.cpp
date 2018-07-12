#include <cstdio>
#include <queue>

using namespace std;
typedef pair<int,int> ii;
const int dx[4]={-1,+1,0,0};
const int dy[4]={0,0,-1,+1};
bool c[55][55];
int b[55][55];

int main(void){

    int t;
    scanf("%d",&t);
    while(t--){
        int m,n,k,sol;
        scanf("%d %d %d",&m,&n,&k);
        for(int i=0; i<=m+1; i++){
            for(int j=0; j<=n+1; j++){
                b[i][j]=0;
                c[i][j]=false;
            }
        }

        for(int i=0; i<k; i++){
            int t1,t2;
            scanf("%d %d",&t1,&t2);
            b[t1+1][t2+1]=1;
        }

        queue<ii> q;

        sol=0;
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(!c[i][j] && b[i][j]){
                    sol++;
                    q.push(ii(i,j));
                    while(!q.empty()){
                        ii f=q.front();
                        q.pop();
                        for(int u=0; u<4; u++){
                            int nx=f.first+dx[u];
                            int ny=f.second+dy[u];
                            if(!c[nx][ny] && b[nx][ny]){
                                q.push(ii(nx,ny));
                                c[nx][ny]=true;
                            }
                        }
                    }
                }
            }
        }

        printf("%d\n",sol);
    }

    return 0;
}
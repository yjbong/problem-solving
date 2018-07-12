#include <cstdio>
#include <queue>
using namespace std;
typedef pair<int,int> ii;
int a[502][502];
bool c[502][502];
const int dy[4]={-1,1,0,0};
const int dx[4]={0,0,1,-1};
int main(void){

    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++) scanf("%d",&a[i][j]);

    queue<ii> q;
    int max=0;
    int prt=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i][j] && !c[i][j]){
                q.push(ii(i,j));
                c[i][j]=true;
                prt++;
                int cur=0;
                while(!q.empty()){
                    ii f=q.front();
                    q.pop();
                    int fy=f.first;
                    int fx=f.second;
                    cur++;
                    for(int k=0; k<4; k++){
                        int cy=fy+dy[k];
                        int cx=fx+dx[k];
                        if(a[cy][cx] && !c[cy][cx]){
                            q.push(ii(cy,cx));
                            c[cy][cx]=true;
                        }
                    }
                }
                if(max<cur) max=cur;
            }
        }
    }
    printf("%d\n%d\n",prt,max);
    return 0;
}
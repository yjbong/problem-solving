#include <cstdio>
#include <queue>
#define INF 1000000000
using namespace std;
typedef struct _a{
    int y;
    int x;
    int brk;
}iii;
int min2(int a,int b){
    if(a<b) return a;
    else return b;
}
const int dy[4]={1,-1,0,0};
const int dx[4]={0,0,-1,1};

int s[2][1111][1111];
int b[1111][1111];

int main(void){

    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0; i<=n+1; i++) b[i][0]=2,b[i][m+1]=2;
    for(int j=0; j<=m+1; j++) b[0][j]=2,b[n+1][j]=2;

    for(int i=0; i<=n+1; i++){
        for(int j=0; j<=m+1; j++){
            s[0][i][j]=INF;
            s[1][i][j]=INF;
        }
    }
    s[0][1][1]=1;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++) scanf("%1d",&b[i][j]);

    iii t;
    t.y=1,t.x=1,t.brk=0;
    queue<iii> q;
    q.push(t);
    while(!q.empty()){

        iii f=q.front();
        q.pop();
        int fy=f.y;
        int fx=f.x;
        int fbrk=f.brk;

        for(int i=0; i<4; i++){
            int cy=fy+dy[i];
            int cx=fx+dx[i];
            if(b[cy][cx]<2){
                if(b[cy][cx]==0){
                    if(s[fbrk][cy][cx]>s[fbrk][fy][fx]+1){
                        s[fbrk][cy][cx]=s[fbrk][fy][fx]+1;
                        //if(fbrk==0) s[1][cy][cx]=s[fbrk][fy][fx]+1;

                        iii t;
                        t.y=cy,t.x=cx,t.brk=fbrk;
                        q.push(t);
                    }
                }
                else if(fbrk==0){
                    if(s[1][cy][cx]>s[fbrk][fy][fx]+1){
                        s[1][cy][cx]=s[fbrk][fy][fx]+1;

                        iii t;
                        t.y=cy,t.x=cx,t.brk=1;
                        q.push(t);
                    }
                }
            }
        }
    }

    int sol=min2(s[0][n][m],s[1][n][m]);
    if(sol>=INF) printf("-1\n");
    else printf("%d\n",sol);

    return 0;
}
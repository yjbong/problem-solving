#include <cstdio>
#include <utility>
#include <queue>
#define INF 1000000000
#define H 0
#define V 1
using namespace std;
typedef pair <pair <int, int>, int> iii;

int d[111][111][2];
int a[111][111];
int b[3][2]; int bs;
int e[3][2]; int es;
char s[111];

const int dy[4]={-1,1,0,0};
const int dx[4]={0,0,-1,1};

int n;

iii start,end;
queue <iii> q;

int main(void){

    scanf("%d\n",&n);
    for(int i=0; i<=n+1; i++) a[i][0]=a[i][n+1]=1;
    for(int i=0; i<=n+1; i++) a[0][i]=a[n+1][i]=1;

    bs=es=0;
    for(int i=1; i<=n; i++){
        gets(s);
        for(int j=1; j<=n; j++){
            if(s[j-1]=='1') a[i][j]=1;
            else a[i][j]=0;

            if(s[j-1]=='B'){
                b[bs][0]=i; b[bs][1]=j; bs++;
            }
            else if(s[j-1]=='E'){
                e[es][0]=i; e[es][1]=j; es++;
            }
        }
    }

    for(int i=0; i<=n+1; i++)
        for(int j=0; j<=n+1; j++)
            for(int k=0; k<=1; k++)
                d[i][j][k]=INF;

    start.first.first=b[1][0]; start.first.second=b[1][1];
    if(b[1][0]==b[0][0]) start.second=H; // horizontal
    else start.second=V; // vertical

    end.first.first=e[1][0]; end.first.second=e[1][1];
    if(e[1][0]==e[0][0]) end.second=H; // horizontal
    else end.second=V; // vertical

    q.push(start);
    d[start.first.first][start.first.second][start.second]=0;

    while(!q.empty()){
        iii f=q.front();
        q.pop();
        int fy=f.first.first;
        int fx=f.first.second;
        int fhv=f.second;

        if(fhv==H){
            for(int i=0; i<4; i++){
                int cy=fy+dy[i]; int cx=fx+dx[i];
                if(a[cy][cx-1]==0 && a[cy][cx]==0 && a[cy][cx+1]==0){
                    if(d[cy][cx][H]>d[fy][fx][H]+1){
                        d[cy][cx][H]=d[fy][fx][H]+1;
                        q.push(make_pair(make_pair(cy,cx),H));
                    }
                }
            }
        }
        else{
            for(int i=0; i<4; i++){
                int cy=fy+dy[i]; int cx=fx+dx[i];
                if(a[cy-1][cx]==0 && a[cy][cx]==0 && a[cy+1][cx]==0){
                    if(d[cy][cx][V]>d[fy][fx][V]+1){
                        d[cy][cx][V]=d[fy][fx][V]+1;
                        q.push(make_pair(make_pair(cy,cx),V));
                    }
                }
            }
        }

        bool rotate_ok=true;
        for(int i=fy-1; i<=fy+1; i++)
            for(int j=fx-1; j<=fx+1; j++)
                if(a[i][j]) rotate_ok=false;

        if(rotate_ok){
            if(d[fy][fx][1-fhv]>d[fy][fx][fhv]+1){
                d[fy][fx][1-fhv]=d[fy][fx][fhv]+1;
                q.push(make_pair(make_pair(fy,fx),1-fhv));
            }
        }
    }

    int sol=d[end.first.first][end.first.second][end.second];
    if(sol<INF) printf("%d\n",sol);
    else printf("0\n");

    return 0;
}
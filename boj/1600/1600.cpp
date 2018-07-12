#include <cstdio>
#include <queue>
#include <utility>
#define INF 1000000000
using namespace std;
typedef pair<pair<int,int>,int> iii;

queue <iii> q;
int a[222][222];
int d[222][222][33];
int k,w,h;

const int dy[4]={-1,+1,0,0};
const int dx[4]={0,0,+1,-1};

const int ky[8]={-2,-2,-1,-1,+1,+1,+2,+2};
const int kx[8]={-1,+1,-2,+2,-2,+2,-1,+1};

int main(void){

    scanf("%d",&k);
    scanf("%d %d",&w,&h);

    for(int i=0; i<=h+3; i++) a[i][0]=a[i][1]=a[i][w+2]=a[i][w+3]=1;
    for(int j=0; j<=w+3; j++) a[0][j]=a[1][j]=a[h+2][j]=a[h+3][j]=1;
    for(int i=2; i<=h+1; i++)
        for(int j=2; j<=w+1; j++) scanf("%d",&a[i][j]);

    for(int i=0; i<=h+3; i++)
        for(int j=0; j<=w+3; j++)
            for(int l=0; l<=k; l++) d[i][j][l]=INF;

    q.push(make_pair(make_pair(2,2),0));
    d[2][2][0]=0;

    while(!q.empty()){

        iii f=q.front();
        q.pop();
        int fy=f.first.first;
        int fx=f.first.second;
        int fk=f.second;

        for(int i=0; i<4; i++){
            int cy=fy+dy[i];
            int cx=fx+dx[i];
            if(a[cy][cx]==0 && d[cy][cx][fk]>d[fy][fx][fk]+1){
                d[cy][cx][fk]=d[fy][fx][fk]+1;
                q.push(make_pair(make_pair(cy,cx),fk));
            }
        }

        if(fk<k){
            for(int i=0; i<8; i++){
                int cy=fy+ky[i];
                int cx=fx+kx[i];
                if(a[cy][cx]==0 && d[cy][cx][fk+1]>d[fy][fx][fk]+1){
                    d[cy][cx][fk+1]=d[fy][fx][fk]+1;
                    q.push(make_pair(make_pair(cy,cx),fk+1));
                }
            }
        }
    }

    int sol=INF;
    for(int i=0; i<=k; i++){
        if(sol>d[h+1][w+1][i]) sol=d[h+1][w+1][i];
    }
    if(sol<INF) printf("%d\n",sol);
    else printf("-1\n");

    return 0;
}
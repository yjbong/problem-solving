#include <cstdio>
#include <queue>
#define Y 0
#define S 1
using namespace std;

typedef struct _p{
    int y;
    int x;
}P;

typedef pair<int,int> ii;
const int dy[4]={-1,1,0,0};
const int dx[4]={0,0,1,-1};

int c[7];
P p[7];
char l[10];

int a[7][7];
int b[7][7];
int ch[7][7];


int main(void){

    for(int i=1; i<=5; i++){
        scanf("%s",l);
        for(int j=1; j<=5; j++){
            if(l[j-1]=='S') a[i][j]=S;
        }
    }

    queue <ii> q;
    int sol=0;

    for(c[0]=0; c[0]<19; c[0]++)
    for(c[1]=c[0]+1; c[1]<20; c[1]++)
    for(c[2]=c[1]+1; c[2]<21; c[2]++)
    for(c[3]=c[2]+1; c[3]<22; c[3]++)
    for(c[4]=c[3]+1; c[4]<23; c[4]++)
    for(c[5]=c[4]+1; c[5]<24; c[5]++)
    for(c[6]=c[5]+1; c[6]<25; c[6]++){

        for(int i=0; i<7; i++) p[i].y=c[i]/5+1, p[i].x=(c[i]%5)+1;
        int ss=0;
        for(int i=0; i<7; i++) if(a[p[i].y][p[i].x]) ss++;
        if(ss<4) continue;

        for(int i=0; i<7; i++) for(int j=0; j<7; j++) b[i][j]=0,ch[i][j]=0;
        for(int i=0; i<7; i++) b[p[i].y][p[i].x]=1;

        q.push(ii(p[0].y,p[0].x));
        ch[p[0].y][p[0].x]=1;

        int seg=0;
        while(!q.empty()){

            ii f=q.front();
            q.pop();
            int fy=f.first;
            int fx=f.second;
            seg++;

            for(int i=0; i<4; i++){
                int cy=fy+dy[i];
                int cx=fx+dx[i];
                if(!ch[cy][cx] && b[cy][cx]){
                    q.push(ii(cy,cx));
                    ch[cy][cx]=1;
                }
            }
        }

        if(seg==7) sol++;
    }
    printf("%d\n",sol);
    return 0;
}
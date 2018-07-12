#include <stdio.h>
#define INF 1000000000000000000ll
#define SELF 0
#define N 1
#define E 2
#define W 3
#define S 4
typedef struct _dot{
    long long x;
    long long y;
}DOT;
DOT dot[111111];
long long d[111111][5];
long long diffx[5]={0,0,-1,1,0};
long long diffy[5]={0,1,0,0,-1};

long long abs2(long long a){

    if(a<0) return (-a);
    else return a;
}

int main(void){

    long long i,j,k,n,cur,sol;
    scanf("%lld", &n);
    for(i=0; i<=n; i++) scanf("%lld %lld", &(dot[i].x),&(dot[i].y));
    d[0][0]=d[0][1]=d[0][2]=d[0][3]=d[0][4]=0;

    for(j=0; j<=4; j++){
        d[1][j]=abs2(dot[1].x+diffx[j]-dot[0].x)+abs2(dot[1].y+diffy[j]-dot[0].y);
    }

    for(i=2; i<=n; i++){
        for(j=0; j<=4; j++){
            d[i][j]=INF;
            for(k=0; k<=4; k++){
                cur=d[i-1][k]+abs2(dot[i].x+diffx[j]-(dot[i-1].x+diffx[k]))+abs2(dot[i].y+diffy[j]-(dot[i-1].y+diffy[k]));
                if(d[i][j]>cur) d[i][j]=cur;
            }
        }
    }

    sol=d[n][0];
    for(i=1; i<=4; i++) if(sol>d[n][i]) sol=d[n][i];
    printf("%lld\n", sol);
    return 0;
}
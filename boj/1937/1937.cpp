#include <cstdio>
#include <algorithm>
#define INF 2147483647
using namespace std;

typedef struct _cell{
    int y;
    int x;
    int h;
}CELL;

const int dy[4]={1,-1,0,0};
const int dx[4]={0,0,-1,1};

int a[502][502];
int d[502][502];
CELL c[502*502];
int cs;

bool cmp(CELL c1, CELL c2){
    if(c1.h>c2.h) return true;
    else return false;
}
int main(void){

    int n;
    scanf("%d",&n);
    for(int i=0; i<=n+1; i++){
        a[i][0]=a[0][i]=INF;
        a[i][n+1]=a[n+1][i]=INF;
    }

    cs=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d",&a[i][j]);
            c[cs].y=i, c[cs].x=j, c[cs].h=a[i][j];
            cs++;
        }
    }
    sort(c,c+cs,cmp);
    int sol=0;
    for(int i=0; i<cs; i++){
        int cy=c[i].y, cx=c[i].x;
        int cm=0;
        for(int j=0; j<4; j++){
            int ccy=cy+dy[j], ccx=cx+dx[j];
            if(a[ccy][ccx]>a[cy][cx] && d[ccy][ccx]>cm) cm=d[ccy][ccx];
        }
        d[cy][cx]=cm+1;
        if(sol<d[cy][cx]) sol=d[cy][cx];
    }
    printf("%d\n",sol);
    return 0;
}
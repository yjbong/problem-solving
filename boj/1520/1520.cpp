#include <stdio.h>
#include <stdlib.h>

typedef struct _cell{
    int y;
    int x;
    int h;
}CELL;

int b[502][502];
int d[502][502];
CELL c[502*502];
int cs;

int cmp(const void *a, const void *b){

    if( ((CELL*)a)->h < ((CELL*)b)->h) return 1;
    else return 0;
}

int main(void){

    int i,j,m,n;
    scanf("%d %d",&m,&n);
    for(i=0; i<=m+1; i++) b[i][0]=0,b[i][n+1]=0;
    for(j=0; j<=n+1; j++) b[0][j]=0,b[m+1][j]=0;

    cs=0;
    for(i=1; i<=m; i++){
        for(j=1; j<=n; j++){
            scanf("%d",&b[i][j]);
            d[i][j]=0;
            c[cs].y=i, c[cs].x=j, c[cs].h=b[i][j];
            cs++;
        }
    }
    qsort(c,cs,sizeof(CELL),cmp);
    d[1][1]=1;
    for(i=0; i<cs; i++){
        if(b[c[i].y][c[i].x-1]>b[c[i].y][c[i].x]) d[c[i].y][c[i].x]+=d[c[i].y][c[i].x-1];
        if(b[c[i].y][c[i].x+1]>b[c[i].y][c[i].x]) d[c[i].y][c[i].x]+=d[c[i].y][c[i].x+1];
        if(b[c[i].y-1][c[i].x]>b[c[i].y][c[i].x]) d[c[i].y][c[i].x]+=d[c[i].y-1][c[i].x];
        if(b[c[i].y+1][c[i].x]>b[c[i].y][c[i].x]) d[c[i].y][c[i].x]+=d[c[i].y+1][c[i].x];
    }

    printf("%d\n",d[m][n]);
    return 0;
}
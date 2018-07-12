#include <cstdio>
#define L 0
#define R 1
#define D 2
#define MINF -2000000000
int a[1111][1111];
int d[1111][1111][3];
int main(void){

    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d",&a[i][j]);
        }
    }

    d[1][1][L]=d[1][1][R]=d[1][1][D]=a[1][1];
    for(int i=2; i<=m; i++){
        d[1][i][R]=d[1][i-1][R]+a[1][i];
        d[1][i][L]=d[1][i][D]=MINF;
    }

    for(int i=2; i<=n; i++){
        int cmax;
        for(int j=1; j<=m; j++){
            if(i-1>0){
                cmax=MINF;
                if(cmax<d[i-1][j][L]+a[i][j]) cmax=d[i-1][j][L]+a[i][j];
                if(cmax<d[i-1][j][R]+a[i][j]) cmax=d[i-1][j][R]+a[i][j];
                if(cmax<d[i-1][j][D]+a[i][j]) cmax=d[i-1][j][D]+a[i][j];
                d[i][j][D]=cmax;
            }
        }
        for(int j=1; j<=m; j++){
            if(j-1>0){
                cmax=MINF;
                if(cmax<d[i][j-1][R]+a[i][j]) cmax=d[i][j-1][R]+a[i][j];
                if(cmax<d[i][j-1][D]+a[i][j]) cmax=d[i][j-1][D]+a[i][j];
                d[i][j][R]=cmax;
            }
            else d[i][j][R]=MINF;
        }
        for(int j=m; j>=1; j--){
            if(j+1<=m){
                cmax=MINF;
                if(cmax<d[i][j+1][L]+a[i][j]) cmax=d[i][j+1][L]+a[i][j];
                if(cmax<d[i][j+1][D]+a[i][j]) cmax=d[i][j+1][D]+a[i][j];
                d[i][j][L]=cmax;
            }
            else d[i][j][L]=MINF;
        }
    }

    int sol=d[n][m][L];
    if(sol<d[n][m][R]) sol=d[n][m][R];
    if(sol<d[n][m][D]) sol=d[n][m][D];
    printf("%d\n",sol);

    return 0;
}
#include <cstdio>
#define MINF -1000000000

int n,m;
int a[111];
int d[111][111];

int main(void){

    scanf("%d %d",&n,&m);
    for(int i=1; i<=n; i++) scanf("%d",&a[i]);
    for(int i=0; i<=n; i++)
        for(int j=0; j<=m; j++) d[i][j]=MINF;

    d[0][0]=0; d[1][1]=a[1];
    for(int i=2; i<=n; i++){
        for(int j=1; j<=m; j++){
            for(int k=0; k<i-1; k++) if(d[i][j]<d[k][j-1]) d[i][j]=d[k][j-1];
            if(d[i][j]<d[i-1][j]) d[i][j]=d[i-1][j];
            if(d[i][j]>MINF) d[i][j]+=a[i];
        }
    }
    int sol=MINF;
    for(int i=0; i<=n; i++) if(sol<d[i][m]) sol=d[i][m];
    printf("%d\n",sol);
    return 0;
}
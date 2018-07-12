#include <cstdio>
int d[2][31][2];
int a[1001];
int main(void){

    int t,w;
    scanf("%d %d",&t,&w);
    for(int i=1; i<=t; i++){
        scanf("%d",&a[i]);
        a[i]--;
    }
    int max=0;
    d[0][0][0]=(a[1]==0);
    if(max<d[1][0][0]) max=d[0][0][0];
    d[0][1][1]=(a[1]==1);
    if(max<d[0][1][1]) max=d[0][1][1];
    for(int i=2; i<=t; i++){
        for(int j=0; j<=w; j++){

            int cmax;

            cmax=d[0][j][0];
            if(j>0 && cmax<d[0][j-1][1]) cmax=d[0][j-1][1];
            d[1][j][0]=cmax+(a[i]==0);
            if(max<d[1][j][0]) max=d[1][j][0];

            cmax=d[0][j][1];
            if(j>0 && cmax<d[0][j-1][0]) cmax=d[0][j-1][0];
            d[1][j][1]=cmax+(a[i]==1);
            if(max<d[1][j][1]) max=d[1][j][1];
        }

        for(int j=0; j<=w; j++){
            d[0][j][0]=d[1][j][0];
            d[0][j][1]=d[1][j][1];
        }
    }
    printf("%d\n",max);
    return 0;
}
#include <stdio.h>
int b[1000][1000];
int d[1000][1000];
int min2(int a, int b){
    if(a<b) return a;
    else return b;
}
int main(void){

    int i,j,n,m,max;
    scanf("%d %d",&n,&m);
    for(i=0; i<n; i++)
        for(j=0; j<m; j++) scanf("%1d",&b[i][j]);

    for(i=0; i<n; i++){
        if(b[i][0]) d[i][0]=1;
        else d[i][0]=0;
    }
    for(j=0; j<m; j++){
        if(b[0][j]) d[0][j]=1;
        else d[0][j]=0;
    }
    for(i=1; i<n; i++){
        for(j=1; j<m; j++){
            if(b[i][j]) d[i][j]=min2(min2(d[i-1][j],d[i][j-1]),d[i-1][j-1])+1;
            else d[i][j]=0;
        }
    }
    max=0;
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            if(max<d[i][j]) max=d[i][j];

    printf("%d\n",max*max);
    return 0;
}
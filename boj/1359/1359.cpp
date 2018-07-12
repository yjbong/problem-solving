#include <stdio.h>
long long d[10][10];
int main(void){

    long long bunmo,bunja,i,j,n,m,k;
    double sol;
    for(i=0; i<10; i++) d[0][i]=0;
    for(j=0; j<10; j++) d[j][0]=1;
    for(i=1; i<10; i++){
        for(j=1; j<10; j++){
            if(i<j) d[i][j]=0;
            else d[i][j]=d[i-1][j-1]+d[i-1][j];
        }
    }
    scanf("%lld %lld %lld",&n,&m,&k);
    bunmo=d[n][m];
    bunja=0;
    for(i=k; i<=m; i++)
        bunja+=d[m][i]*d[n-m][m-i];
    sol=(double)bunja/bunmo;
    printf("%.10lf\n",sol);
    return 0;
}
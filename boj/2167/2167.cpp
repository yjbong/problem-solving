#include <stdio.h>
long long d[301][301];
long long a[301][301];
int main(void){

    long long i,j,x,y,n,m,k;
    scanf("%lld %lld",&n,&m);
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++) scanf("%lld",&a[i][j]);

    d[1][1]=a[1][1];
    for(i=2; i<=n; i++) d[i][1]=d[i-1][1]+a[i][1];
    for(j=2; j<=m; j++) d[1][j]=d[1][j-1]+a[1][j];

    for(i=2; i<=n; i++)
        for(j=2; j<=m; j++)
            d[i][j]=d[i-1][j]+d[i][j-1]-d[i-1][j-1]+a[i][j];

    scanf("%lld",&k);
    while(k--){
        scanf("%lld %lld %lld %lld",&i,&j,&x,&y);
        printf("%lld\n",d[x][y]-d[x][j-1]-d[i-1][y]+d[i-1][j-1]);
    }
    return 0;
}
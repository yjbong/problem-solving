#include <cstdio>
#define MOD 1000001ll

long long d[111][111][111];
int main(void){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);

    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            d[i][j][0]=1;
            d[i][j][1]=i*j;
            d[i][j][2]=((i*j)*(i*j-1))/2;
        }
    }

    for(int i=2; i<=n; i++)
        for(int j=2; j<=m; j++)
            for(int l=2; l<=k; l++)
                d[i][j][l]=((d[i-1][j][l])+(j*d[i-1][j-1][l-1]+j*(i-1)*d[i-2][j-1][l-2])+(j*(j-1)/2*d[i-1][j-2][l-2]))%MOD;

    printf("%lld\n",d[n][m][k]);
    return 0;
}
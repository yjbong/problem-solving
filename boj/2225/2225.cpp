#include <cstdio>
#define MOD 1000000000
long long d[222][222]; //d[i][j]: using i integers and its sum is j
int main(void){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0; i<=k; i++) d[i][0]=1;
    for(int i=1; i<=k; i++){
        for(int j=1; j<=n; j++){
            for(int k=0; k<=n; k++){
                if(j-k<0) break;
                d[i][j]=(d[i][j]+d[i-1][j-k])%MOD;
            }
        }
    }
    printf("%lld\n",d[k][n]);
    return 0;
}
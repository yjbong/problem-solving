#include <cstdio>
#define MOD 9901

int d[222][111];
int main(void){

    int n,k;
    scanf("%d %d",&n,&k);

    d[1][1]=1;
    for(int i=3; i<=n; i+=2){
        for(int j=1; j<=k; j++){
            for(int l=1; l<=i-2; l+=2){
                for(int m=1; m<j-1; m++){
                    d[i][j]=(d[i][j]+d[l][j-1]*d[i-l-1][m]*2)%MOD;
                }
                if(l<=i-l-1){
                    if(l==i-l-1) d[i][j]=(d[i][j]+d[l][j-1]*d[i-l-1][j-1])%MOD;
                    else d[i][j]=(d[i][j]+d[l][j-1]*d[i-l-1][j-1]*2)%MOD;
                }
            }
        }
    }

    printf("%d\n",d[n][k]);
    return 0;
}
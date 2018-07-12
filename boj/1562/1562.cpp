#include <cstdio>
#define BIG 1000000000ll
typedef long long ll;
ll d[101][10][1<<10];

int main(void){

    int n;
    scanf("%d",&n);
    for(int j=0; j<10; j++) d[1][j][1<<j]=1;
    for(int i=2; i<=n; i++){
        for(int j=0; j<10; j++){
            for(int k=0; k<(1<<10); k++){
                if(k&(1<<j)){
                    if(j>0){
                        d[i][j][k]=(d[i][j][k]+d[i-1][j-1][k])%BIG;
                        d[i][j][k]=(d[i][j][k]+d[i-1][j-1][k-(1<<j)])%BIG;
                    }
                    if(j<9){
                        d[i][j][k]=(d[i][j][k]+d[i-1][j+1][k])%BIG;
                        d[i][j][k]=(d[i][j][k]+d[i-1][j+1][k-(1<<j)])%BIG;
                    }
                }
            }
        }
    }

    ll sol=0;
    for(int j=1; j<10; j++)
        sol=(sol+d[n][j][(1<<10)-1])%BIG;
    printf("%lld\n",sol);

    return 0;
}
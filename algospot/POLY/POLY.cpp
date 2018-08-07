#include <cstdio>
#define MOD 10000000
int c,n;
int d[111][111];
int main(void){
        for(int i=0; i<=100; i++){
                for(int j=0; j<=i; j++){
                        if(i==j) d[i][j]=1;
                        else{
                                for(int k=1; k<=i-j; k++)
                                        d[i][j]=(d[i][j]+(j+k-1)*d[i-j][k])%MOD;
                        }
                }
        }
        scanf("%d",&c);
        while(c--){
                scanf("%d",&n);
                int ans=0;
                for(int i=0; i<=n; i++) ans=(ans+d[n][i])%MOD;
                printf("%d\n",ans);
        }
        return 0;
}
#include <cstdio>
#define MOD 10007
typedef long long ll;
int c,n,p;
ll mat[20][100][100]; // mat[i]=(mat[0])^(2^i)
ll ans[2][100][100];
int main(void){
        scanf("%d",&c);
        while(c--){
                scanf("%d %d",&n,&p);
                for(int i=0; i<n; i++)
                        for(int j=0; j<n; j++) scanf("%lld",&mat[0][i][j]);

                for(int i=1; i<20; i++){
                        for(int j=0; j<n; j++){
                                for(int k=0; k<n; k++){
                                        mat[i][j][k]=0;
                                        for(int l=0; l<n; l++)
                                                mat[i][j][k]=(mat[i][j][k]+mat[i-1][j][l]*mat[i-1][l][k])%MOD;
                                }
                        }
                }

                for(int i=0; i<n; i++)
                        for(int j=0; j<n; j++)
                                ans[0][i][j]=(i==j?1:0);

                int cur=1;
                for(int i=0; i<20; i++){
                        if(p&(1<<i)){
                                for(int j=0; j<n; j++){
                                        for(int k=0; k<n; k++){
                                                ans[cur][j][k]=0;
                                                for(int l=0; l<n; l++)
                                                        ans[cur][j][k]=(ans[cur][j][k]+mat[i][j][l]*ans[1-cur][l][k])%MOD;
                                        }
                                }
                                cur=1-cur;
                        }
                }

                for(int i=0; i<n; i++){
                        for(int j=0; j<n; j++)
                                printf("%lld ", ans[1-cur][i][j]);
                        printf("\n");
                }
        }
        return 0;
}
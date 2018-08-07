#include <cstdio>
#define MOD 1000000007
int t,m,c;
int p[111];
int d[111][5555];
int main(void){
        scanf("%d",&t);
        while(t--){
                scanf("%d %d",&m,&c);
                for(int i=1; i<=c; i++) scanf("%d",&p[i]);
                for(int i=0; i<=m; i++) d[0][i]=0;
                d[0][0]=1;
                for(int i=1; i<=c; i++){
                        for(int j=0; j<=m; j++){
                                d[i][j]=0;
                                int k=0;
                                while(j-k*p[i]>=0){
                                        d[i][j]=(d[i][j]+d[i-1][j-k*p[i]])%MOD;
                                        k++;
                                }
                        }
                }
                printf("%d\n",d[c][m]);
        }
        return 0;
}
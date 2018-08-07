#include <cstdio>
int n;
int t[40+1];
int d[2][40*30+1][40*30+1];
int max2(int a, int b){
    return a>b?a:b;
}
int main(void){

    while(1){
        scanf("%d",&n);
        if(n==0) break;
        int tsum=0;
        for(int i=1; i<=n; i++){
            scanf("%d",&t[i]);
            tsum+=t[i];
        }

        for(int i=0; i<=tsum; i++)
            for(int j=0; j<=tsum; j++) d[0][i][j]=0;
        d[0][0][0]=1;

        int cur=1;
        for(int i=1; i<=n; i++){
            for(int j=0; j<=tsum; j++){
                for(int k=0; k<=tsum; k++){
                    d[cur][j][k]=0;
                    if(j-t[i]>=0) d[cur][j][k]|=d[1-cur][j-t[i]][k];
                    if(k-t[i]>=0) d[cur][j][k]|=d[1-cur][j][k-t[i]];
                    d[cur][j][k]|=d[1-cur][j][k];
                }
            }
            cur=1-cur;
        }

        int ans=tsum+1;
        for(int i=0; i<=tsum; i++){
            for(int j=0; j<=tsum; j++){
                if(d[1-cur][i][j]){
                    int curans=max2(max2(i,j),tsum-(i+j));
                    if(ans>curans) ans=curans;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
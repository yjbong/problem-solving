#include <cstdio>
typedef struct _gs{
    int x1,y1;
    int x2,y2;
}INFO;
long long d[111][111];
INFO g[111];

int main(void){

    int n,m,k;

    scanf("%d %d %d",&n,&m,&k);
    for(int i=0; i<k; i++)
        scanf("%d %d %d %d",&g[i].x1,&g[i].y1,&g[i].x2,&g[i].y2);
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i==0 && j==0) d[i][j]=1;
            else{
                bool x_ok=true;
                if(i-1<0) x_ok=false;
                if(x_ok){
                    for(int u=0; u<k; u++){
                        if((g[u].x1==i && g[u].y1==j && g[u].x2==i-1 && g[u].y2==j) ||
                            (g[u].x1==i-1 && g[u].y1==j && g[u].x2==i && g[u].y2==j)){
                            x_ok=false;
                            break;
                        }
                    }
                }
                if(x_ok) d[i][j]+=d[i-1][j];

                bool y_ok=true;
                if(j-1<0) y_ok=false;
                if(y_ok){
                    for(int u=0; u<k; u++){
                        if((g[u].x1==i && g[u].y1==j && g[u].x2==i && g[u].y2==j-1) ||
                            (g[u].x1==i && g[u].y1==j-1 && g[u].x2==i && g[u].y2==j)){
                            y_ok=false;
                            break;
                        }
                    }
                }
                if(y_ok) d[i][j]+=d[i][j-1];
            }
        }
    }

    printf("%lld\n",d[n][m]);
    return 0;
}
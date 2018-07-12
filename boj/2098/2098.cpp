#include <cstdio>
#define INF 1000000000
int d[1<<16][16];
int w[16][16];
int main(void){

    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&w[i][j]);
            if(!w[i][j]) w[i][j]=INF;
        }
    }

    for(int i=0; i<(1<<n); i++)
        for(int j=0; j<n; j++) d[i][j]=INF;
    d[1][0]=0; // start from vertex 0

    for(int i=0; i<(1<<n); i++)
        for(int j=0; j<n; j++)
            if(!(i&(1<<j)))
                for(int k=0; k<n; k++)
                    if(i&(1<<k))
                        if(d[i+(1<<j)][j]>d[i][k]+w[k][j]) d[i+(1<<j)][j]=d[i][k]+w[k][j];
    int sol=INF;
    for(int i=0; i<n; i++)
        if(sol>d[(1<<n)-1][i]+w[i][0]) sol=d[(1<<n)-1][i]+w[i][0];

    printf("%d\n",sol);
    return 0;
}
#include <cstdio>
bool d[201][201];
int main(void){

    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0; i<m; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        d[a][b]=d[b][a]=true;
    }
    int sol=0;
    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++)
            for(int k=j+1; k<=n; k++)
                if(!d[i][j] && !d[j][k] && !d[i][k]) sol++;

    printf("%d\n",sol);
    return 0;
}
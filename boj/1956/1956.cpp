#include <cstdio>
#define INF 100000000
int v,e;
int a[401][401];
int d[401][401];
int main(void){

    scanf("%d %d",&v,&e);
    for(int i=1; i<=v; i++){
        for(int j=1; j<=v; j++){
            a[i][j]=INF;
            d[i][j]=INF;
        }
    }

    for(int i=0; i<e; i++){
        int f,t,c;
        scanf("%d %d %d",&f,&t,&c);
        if(a[f][t]>c){
            a[f][t]=c;
            d[f][t]=c;
        }
    }

    for(int k=1; k<=v; k++)
        for(int i=1; i<=v; i++)
            for(int j=1; j<=v; j++)
                if(d[i][j]>d[i][k]+d[k][j]) d[i][j]=d[i][k]+d[k][j];

    int sol=INF;
    for(int i=1; i<=v; i++)
        for(int j=1; j<=v; j++)
            if(sol>d[i][j]+d[j][i]) sol=d[i][j]+d[j][i];

    if(sol>=INF) printf("-1\n");
    else printf("%d\n",sol);
    return 0;
}
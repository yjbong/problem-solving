#include <cstdio>
#define LIM 1111
#define INF 1000000000
int d[LIM+1];
int p[20];
int g[20];

int main(void){

    int c,n;
    scanf("%d %d",&c,&n);
    for(int i=0; i<n; i++) scanf("%d %d",&p[i],&g[i]);
    for(int i=0; i<=LIM; i++) d[i]=INF;
    d[0]=0;

    for(int i=0; i<n; i++){
        for(int j=0; j<=LIM; j++){
            if(d[j]<INF){
                int curp=p[i];
                int curg=j+g[i];
                while(curg<=LIM){
                    if(d[curg]>d[curg-g[i]]+p[i]) d[curg]=d[curg-g[i]]+p[i];
                    curg+=g[i];
                }
            }
        }
    }

    int sol=d[c];
    for(int i=c+1; i<=LIM; i++)
        if(sol>d[i]) sol=d[i];

    printf("%d\n",sol);
    return 0;
}
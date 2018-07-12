#include <cstdio>
#define INF 1000000000
int a[55][55];
bool c[55];
int main(void){

    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%d",&a[i][j]);

    int sol=INF;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) c[j]=false;
        int csol=0;
        for(int j=0; j<n; j++){
            if(i!=j){
                int notz=0;
                int cm;
                for(int k=0; k<m; k++){
                    if(a[j][k]!=0){
                        cm=k;
                        notz++;
                    }
                }
                if(notz>1) csol++;
                else if(notz==1){
                    if(!c[cm]) c[cm]=true;
                    else csol++;
                }
            }
        }
        if(sol>csol) sol=csol;
    }
    if(sol>=INF) printf("-1\n");
    else printf("%d\n",sol);
    return 0;
}
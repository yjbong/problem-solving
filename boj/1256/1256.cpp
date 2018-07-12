#include <stdio.h>
#define LIM 1000000000000000ll
long long d[201][201];
int main(void){

    long long i,j,n,m,k,cnt,cm,cn;
    for(i=0; i<=200; i++) d[i][0]=1;
    for(i=1; i<=200; i++){
        for(j=1; j<=200; j++){
            if(i<j) d[i][j]=0;
            else{
                if(i/2<j) d[i][j]=d[i][i-j];
                else d[i][j]=d[i-1][j]+d[i-1][j-1];
                if(d[i][j]>LIM) d[i-1][j]=LIM+1;
            }
        }
    }
    scanf("%lld %lld %lld",&n,&m,&k);
    if(k>d[n+m][n]) printf("-1\n");
    else{
        cn=n,cm=m,cnt=n+m;
        while(cn+cm>0){

            if(cn==0){
                printf("z");
                cm--;
            }

            else if(cm==0){
                printf("a");
                cn--;
            }

            else if(k<=d[cn+cm-1][cn-1]){
                cn--;
                printf("a");
            }
            else{
                k-=d[cn+cm-1][cn-1];
                cm--;
                printf("z");
            }
        }
        printf("\n");
    }
    return 0;
}
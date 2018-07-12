#include <stdio.h>

long long d[1111][3];
long long sol[1111];
long long result[1111];

int main(void){

    int i,j,n;

    d[0][0]=1, d[0][1]=0, d[0][2]=0, sol[0]=1;
    d[1][0]=1, d[1][1]=1, d[1][2]=0, sol[1]=2;
    d[2][0]=2, d[2][1]=1, d[2][2]=1, sol[2]=4;

    scanf("%d", &n);
    for(i=2; i<=n; i++){
        d[i][0]=(d[i-1][0]+d[i-1][1]+d[i-1][2])%1000000;
        d[i][1]=d[i-1][0];
        d[i][2]=d[i-2][0];

        sol[i]=(d[i][0]+d[i][1]+d[i][2])%1000000;
    }

    for(i=0; i<=n; i++){
        result[i]=sol[i];
        for(j=0; j<=i-1; j++){
            result[i]=(result[i]+sol[j]*sol[i-j-1])%1000000;
        }
    }

    if(n==0) printf("0\n");
    else printf("%lld\n", result[n]);
    return 0;
}
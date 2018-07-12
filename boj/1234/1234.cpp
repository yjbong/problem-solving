#include <stdio.h>

long long facto[11];
long long d[11][61][61][61];
int main(void){

    long long i,j,k,l,n,r,g,b,cases,sol;

    facto[0]=1;
    for(i=1; i<=10; i++) facto[i]=facto[i-1]*i;

    scanf("%lld %lld %lld %lld",&n,&r,&g,&b);
    if(r>60) r=60;
    if(g>60) g=60;
    if(b>60) b=60;

    for(i=0; i<=n; i++)
        for(j=0; j<=60; j++)
            for(k=0; k<=60; k++)
                for(l=0; l<=60; l++) d[i][j][k][l]=0;

    d[0][r][g][b]=1;
    for(i=0; i<=n-1; i++){
        for(j=0; j<=60; j++){
            for(k=0; k<=60; k++){
                for(l=0; l<=60; l++){

                   if(d[i][j][k][l]>0){

                        // only use RED
                        if(j>=i+1){
                            cases=1;
                            d[i+1][j-(i+1)][k][l]+=d[i][j][k][l]*cases;
                        }
                        // only use GREEN
                        if(k>=i+1){
                            cases=1;
                            d[i+1][j][k-(i+1)][l]+=d[i][j][k][l]*cases;
                        }
                        // only use BLUE
                        if(l>=i+1){
                            cases=1;
                            d[i+1][j][k][l-(i+1)]+=d[i][j][k][l]*cases;
                        }
                        // use RED and GREEN
                        if((i+1)%2==0 && j>=(i+1)/2 && k>=(i+1)/2){
                            cases=facto[i+1]/(facto[(i+1)/2]*facto[(i+1)/2]);
                            d[i+1][j-(i+1)/2][k-(i+1)/2][l]+=d[i][j][k][l]*cases;
                        }
                        // use RED and BLUE
                        if((i+1)%2==0 && j>=(i+1)/2 && l>=(i+1)/2){
                            cases=facto[i+1]/(facto[(i+1)/2]*facto[(i+1)/2]);
                            d[i+1][j-(i+1)/2][k][l-(i+1)/2]+=d[i][j][k][l]*cases;
                        }
                        // use GREEN and BLUE
                        if((i+1)%2==0 && k>=(i+1)/2 && l>=(i+1)/2){
                            cases=facto[i+1]/(facto[(i+1)/2]*facto[(i+1)/2]);
                            d[i+1][j][k-(i+1)/2][l-(i+1)/2]+=d[i][j][k][l]*cases;
                        }
                        // use RED, GREEN and BLUE
                        if((i+1)%3==0 && j>=(i+1)/3 && k>=(i+1)/3 && l>=(i+1)/3){
                            cases=facto[i+1]/(facto[(i+1)/3]*facto[(i+1)/3]*facto[(i+1)/3]);
                            d[i+1][j-(i+1)/3][k-(i+1)/3][l-(i+1)/3]+=d[i][j][k][l]*cases;
                        }
                    }
                }
            }
        }
    }
    sol=0;
    for(j=0; j<=60; j++)
        for(k=0; k<=60; k++)
            for(l=0; l<=60; l++)
                sol+=d[n][j][k][l];

    printf("%lld\n",sol);
    return 0;
}
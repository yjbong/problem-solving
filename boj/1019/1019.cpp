#include <stdio.h>
long long d[12][10];
long long pw[12];
long long sol[10];
int main(void){

    long long i,j,k;
    long long n,dgts,tmp;
    pw[0]=1;
    for(i=1; i<12; i++) pw[i]=pw[i-1]*10;
    scanf("%lld",&n);
    tmp=n,dgts=0;
    while(tmp>0){
        tmp/=10;
        dgts++;
    }
    d[0][0]=0,d[0][n/pw[dgts-1]]=n%pw[dgts-1]+1;
    for(i=1; i<n/pw[dgts-1]; i++) d[0][i]=pw[dgts-1];

    for(i=1,j=dgts-1; i<dgts; i++,j--){
        for(k=0; k<=9; k++){
            if(k==0){
                d[i][k]=(n/pw[j]-1)*pw[j-1];
                tmp=n%pw[j]+1;
                if(tmp>pw[j-1]) tmp=pw[j-1];
                else if(tmp<0) tmp=0;
                d[i][k]+=tmp;
            }
            else{
                d[i][k]=(n/pw[j])*pw[j-1];
                tmp=n%pw[j]-k*pw[j-1]+1;
                if(tmp>pw[j-1]) tmp=pw[j-1];
                else if(tmp<0) tmp=0;
                d[i][k]+=tmp;
            }
        }
    }

    for(i=0; i<=9; i++) sol[i]=0;
    for(i=0; i<dgts; i++){
        for(j=0; j<=9; j++){
            sol[j]+=d[i][j];
        }
    }

    for(i=0; i<=9; i++){
        printf("%lld",sol[i]);
        if(i==9) printf("\n");
        else printf(" ");
    }
    return 0;
}
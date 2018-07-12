#include <stdio.h>

int sum[12][10];
int acc[11];
int digits;
int main(void){

    int i,j,n;
    for(i=0; i<10; i++) sum[1][i]=i;
    for(i=2; i<12; i++){
        sum[i][0]=0;
        for(j=1; j<10; j++){
            sum[i][j]=sum[i][j-1]+sum[i-1][j];
        }
    }
    acc[1]=9;
    for(i=2; i<=10; i++){
        acc[i]=acc[i-1]+sum[i][11-i];
    }

    scanf("%d",&n);
    if(n>1022) printf("-1\n");
    else if(n<10) printf("%d\n",n);
    else{
        n--;
        digits=0;
        while(digits<=10){
            if(acc[digits]>n){
                n=n-acc[digits-1];
                break;
            }
            digits++;
        }
        i=digits;
        while(1){
            if(i==1){
                printf("%d\n",n);
                break;
            }
            for(j=0; j<10; j++){
                if(sum[i][j]>n){
                    printf("%d",j+i-2);
                    n-=sum[i][j-1];
                    break;
                }
            }
            i--;
        }
    }
    return 0;
}
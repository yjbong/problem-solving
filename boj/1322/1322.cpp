#include <stdio.h>
int main(void){

    long long i,j,x,k,tmp,sol;
    long long bit_weight[32];

    scanf("%lld %lld", &x, &k);

    tmp=1;
    i=0;
    while(x>0){
        if(x%2==0){
            bit_weight[i]=tmp;
            i++;
        }
        x/=2;
        tmp*=2;
    }
    if(i<32){
        bit_weight[i]=tmp;
        for(j=i+1; j<32; j++) bit_weight[j]=bit_weight[j-1]*2;
    }

    i=0, sol=0;
    while(k>0){
        if(k%2==1) sol+=bit_weight[i];
        k/=2;
        i++;
    }
    printf("%lld\n", sol);
    return 0;
}
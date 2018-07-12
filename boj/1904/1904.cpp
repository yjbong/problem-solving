#include <stdio.h>
long long d[1111111];
int main(void){

        long long n,i;
        d[0]=1,d[1]=1;
        for(i=2; i<=1000000; i++) d[i]=(d[i-1]+d[i-2])%15746;
        scanf("%lld",&n);
        printf("%lld\n",d[n]);

        return 0;
}
#include <stdio.h>
#include <math.h>
int main(void){
        long long N, result;
        scanf("%lld", &N);
        result=(long long)floor((sqrt(8*N+1)-1)/2.0);
        printf("%lld\n", result);
        return 0;
}
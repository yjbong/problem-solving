#include <stdio.h>
#define MAX_DIVS 50
int main(void){
        long long i;
        long long divisors;
        long long divisor[MAX_DIVS];
        long long max_div, min_div;
        scanf("%lld", &divisors);
        if(divisors == 0) printf("0\n");
        else{
                for(i=0; i<divisors; i++) scanf("%lld", &(divisor[i]));
                max_div = divisor[0];
                min_div = divisor[0];
                for(i=1; i<divisors; i++){
                        if(max_div < divisor[i]) max_div = divisor[i];
                        if(min_div > divisor[i]) min_div = divisor[i];
                }
                printf("%lld\n", max_div*min_div);
        }
        return 0;
}
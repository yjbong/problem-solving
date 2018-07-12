#include <stdio.h>
int main(void){
        long long n, s;
        scanf("%lld", &n);
        if(n==1) s=5;
        else s=n*(n+1)/2*5-n*n+1;
        printf("%lld\n", s%45678);
        return 0;
}
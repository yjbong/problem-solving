#include <stdio.h>
int main(void){
    long long i,n;
    scanf("%lld", &n);
    i=0;
    while(n>1+3*i*(i+1)) i++;
    printf("%lld\n", i+1);
    return 0;
}
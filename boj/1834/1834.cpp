#include <cstdio>
int main(void){
    long long n,sol;
    scanf("%lld",&n);
    sol=((n-1)*n/2)*n+(n-1)*n/2;
    printf("%lld\n",sol);
    return 0;
}
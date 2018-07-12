#include <stdio.h>
#define MAX 1000000
#define DIV 1000000000
long long d[MAX+1];
int main(void){
    long long i,n;
    scanf("%lld", &n);
    d[1]=0,d[2]=1;
    for(i=3; i<=n; i++)
        d[i]=(d[i-1]*(i-1)+d[i-2]*(i-1))%DIV;
    printf("%lld\n", d[n]);
    return 0;
}
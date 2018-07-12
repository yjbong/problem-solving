#include <stdio.h>
long long p[91];
int main(void){
    int i,n;
    p[1]=p[2]=1;
    for(i=3; i<=90; i++) p[i]=p[i-1]+p[i-2];
    scanf("%d",&n);
    printf("%lld\n", p[n]);
    return 0;
}
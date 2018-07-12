#include <stdio.h>
#define MOD 9901
long long d[100001];
int main(void){
    int i,n;
    scanf("%d",&n);
    d[1]=3,d[2]=7;
    for(i=3; i<=n; i++)
        d[i]=(d[i-1]%MOD+d[i-1]%MOD+d[i-2]%MOD)%MOD;
    printf("%lld\n",d[n]);
    return 0;
}
#include <cstdio>
#define MOD 1000000000
long long d[1000001];
long long p[21];
int main(void){
    int n;
    p[0]=1;
    for(int i=1; i<=20; i++) p[i]=p[i-1]*2;
    scanf("%d",&n);
    d[0]=1;
    for(int i=0; i<=20; i++)
        for(int j=1; j<=n; j++)
            if(j-p[i]>=0) d[j]=(d[j]+d[j-p[i]])%MOD;
    printf("%lld\n",d[n]);
    return 0;
}
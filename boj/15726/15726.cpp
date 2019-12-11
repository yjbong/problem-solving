#include <cstdio>
int main(void){
    long long a,b,c,v1,v2;
    scanf("%lld %lld %lld",&a,&b,&c);
    v1=a*b/c; v2=a*c/b;
    if(v1>v2) printf("%lld\n",v1);
    else printf("%lld\n",v2);
    return 0;
}
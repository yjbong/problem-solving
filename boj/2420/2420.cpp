#include <cstdio>
int main(void){
    long long n,m,s;
    scanf("%lld %lld",&n,&m);
    s=n-m;
    if(s<0) s=-s;
    printf("%lld\n",s);
    return 0;
}
#include <cstdio>
#include <cmath>
typedef long long ll;
int main(void){

    ll n,s;
    scanf("%lld",&n);
    if(sqrt(n)==(long long)sqrt(n)) s=sqrt(n);
    else s=sqrt(n)+1;
    printf("%lld\n",s);
    return 0;
}
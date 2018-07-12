#include <stdio.h>
int main(void){
    long long a,b,s;
    scanf("%lld %lld",&a,&b);
    if(a==1) s=8*b;
    else if(a==5) s=4+8*b;
    else if(b%2==1) s=b/2*8+(9-a);
    else s=b/2*8+a-1;
    printf("%lld\n",s);
    return 0;
}
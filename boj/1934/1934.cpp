#include <stdio.h>
#define SWAP(a,b,tmp) {tmp=a; a=b; b=tmp;}
long long gcd(long long a, long long b){

        long long tmp;
        if(a<b) SWAP(a,b,tmp);
        while(b>0){
                a=a%b;
                SWAP(a,b,tmp);
        }
        return a;
}

int main(void){

        long long a, b, i;
        scanf("%lld", &i);
        while(i--){
                scanf("%lld %lld", &a, &b);
                printf("%lld\n", a*b/gcd(a,b));
        }
        return 0;
}
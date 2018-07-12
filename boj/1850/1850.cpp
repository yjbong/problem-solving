#include <stdio.h>
#define SWAP(a,b,tmp) {tmp=a; a=b; b=tmp;}
long long gcd(long long a, long long b){

        long long tmp;
        while(b>0){
                a=a%b;
                SWAP(a,b,tmp);
        }
        return a;
}

int main(void){

        long long a, b, n, i;
        scanf("%lld %lld", &a, &b);
        n=gcd(a,b);
        for(i=0; i<n; i++) printf("1");
        printf("\n");
        return 0;
}
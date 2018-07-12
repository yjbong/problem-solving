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

    long long x,y;
    long long xygcd;
    long long tiles;
    long long tmp;
    scanf("%lld %lld", &x, &y);

    if(x<y) SWAP(x,y,tmp);
    xygcd=gcd(x,y);
    x/=xygcd, y/=xygcd;
    if(x%y==0) tiles=x;
    else tiles=x+y-1;

    tiles*=xygcd;
    printf("%lld\n", tiles);
    return 0;
}
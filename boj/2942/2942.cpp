#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SWAP(a,b,tmp) {tmp=a; a=b; b=tmp;}

long long divisor[100000];
long long divisors;

long long gcd(long long a, long long b){

    long long tmp;
    if(a<b) SWAP(a,b,tmp);
    while(b>0){
        a=a%b;
        SWAP(a,b,tmp);
    }
    return a;
}

int cmp(const void *a, const void *b){

    if(*((int*)a)>*((int*)b)) return 1;
    else return 0;
}

int main(void){

    long long i,r,g,rg;
    scanf("%lld %lld", &r, &g);

    if(r==0 && g==0) rg=0;
    else if(r==0 && g>0) rg=g;
    else if(r>0 && g==0) rg=r;
    else rg=gcd(r,g);

    divisors=0;
    for(i=1; i<=(long long)(sqrt(rg)); i++){
        if(rg%i==0){
            divisor[divisors++]=i;
            if(i!=rg/i) divisor[divisors++]=rg/i;
        }
    }
    qsort(divisor, divisors, sizeof(long long), cmp);

    for(i=0; i<divisors; i++){
        printf("%lld %lld %lld\n", divisor[i], r/divisor[i], g/divisor[i]);
    }

    return 0;
}
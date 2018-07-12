#include <stdio.h>
#define SWAP(a,b,tmp) {tmp=a; a=b; b=tmp;}

long long num[9];
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

    int i,n;
    long long cur_gcd,mo,ja,tmp;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%lld", &num[i]);

    mo=1;
    for(i=0; i<n; i++){
        cur_gcd=gcd(mo, num[i]);
        mo=(mo/cur_gcd)*num[i];
    }

    ja=0;
    for(i=0; i<n; i++)
        ja+=(mo/num[i]);
    SWAP(mo,ja,tmp);
    cur_gcd=gcd(mo,ja);
    mo/=cur_gcd;
    ja/=cur_gcd;
    printf("%lld/%lld\n", ja,mo);

    return 0;
}
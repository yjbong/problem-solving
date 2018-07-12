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

    long long i,j,k,num[5],ijgcd,ijlcm,ijkgcd,ijklcm,minlcm;
    for(i=0; i<5; i++) scanf("%lld", &num[i]);
    minlcm=-1;
    for(i=0; i<5; i++){
        for(j=i+1; j<5; j++){
            for(k=j+1; k<5; k++){
                ijgcd=gcd(num[i],num[j]);
                ijlcm=num[i]*num[j]/ijgcd;

                ijkgcd=gcd(ijlcm,num[k]);
                ijklcm=ijlcm*num[k]/ijkgcd;
                if(minlcm<0 || minlcm>ijklcm) minlcm=ijklcm;
            }
        }
    }
    printf("%lld\n",minlcm);
    return 0;
}
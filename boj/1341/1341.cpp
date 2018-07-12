#include <stdio.h>

int bin[100];
long long p[100];
int main(void){

    long long a,b,i,binlen,tmp;
    scanf("%lld %lld", &a, &b);

    tmp=1;
    for(i=1; i<=60; i++){
        tmp*=2;
        p[i]=tmp-1;
    }

    binlen=-1;
    for(i=1; i<=60; i++){
        if(p[i]%b==0){
            a*=(p[i]/b);
            binlen=i;
            break;
        }
    }

    if(binlen<0) printf("-1\n");
    else if(a==0) printf("-\n");
    else{
        for(i=binlen-1; i>=0; i--){
            bin[i]=a%2;
            a/=2;
        }
        for(i=0; i<binlen; i++){
            if(bin[i]==1) printf("*");
            else printf("-");
        }
        printf("\n");
    }
    return 0;
}
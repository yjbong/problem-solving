#include <stdio.h>
#define SIZE 10000000
char d[SIZE+1];
long long p[1000000];
int main(void){

    long long i,j,ps,sol,tmp,a,b;
    scanf("%lld %lld",&a,&b);

    d[0]=d[1]=1;
    for(i=2; i<=SIZE; i++)
        if(d[i]==0)
            for(j=i*i; j<=SIZE; j+=i) d[j]=1;

    for(i=0,ps=0; i<=SIZE; i++)
        if(d[i]==0) p[ps++]=i;

    sol=0;
    for(i=0; i<ps; i++){
        tmp=p[i]*p[i];
        if(tmp<=b){
            while(1){
                if(tmp>=a) sol++;
                if(tmp<=b/p[i]) tmp*=p[i];
                else break;
            }
        }
    }

    printf("%lld\n",sol);
    return 0;
}
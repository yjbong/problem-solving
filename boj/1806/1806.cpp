#include <stdio.h>
#define BIGNUM 10000000
long long num[100000];
int main(void){

    long long i;
    long long sum,n,k;
    long long s,e;
    long long minlen;
    scanf("%lld %lld",&n,&k);
    for(i=0; i<n; i++) scanf("%lld",&num[i]);
    s=e=0;
    sum=num[0];
    minlen=BIGNUM;
    while(1){
        if(sum>=k){
            if(e-s+1<minlen) minlen=e-s+1;
            sum-=num[s];
            s++;
            if(s>n-1) break;
            if(s>e){
                e=s;
                sum=num[e];
            }
        }
        else{
            e++;
            if(e>n-1) break;
            sum+=num[e];
        }
    }
    if(sum>=k)
        if(e-s+1<minlen) minlen=e-s+1;

    if(minlen==BIGNUM) printf("0\n");
    else printf("%lld\n",minlen);
    return 0;
}
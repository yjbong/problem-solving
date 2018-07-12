#include <cstdio>
long long tr[1111];
int main(void){

    long long n,c,w,max=0;
    scanf("%lld %lld %lld",&n,&c,&w);
    for(long long i=0; i<n; i++){
        scanf("%lld",&tr[i]);
        if(max<tr[i]) max=tr[i];
    }

    long long sol=0;
    for(long long i=1; i<=max; i++){
        long long c_earn=0;
        for(long long j=0; j<n; j++){
            long long cc_earn=i*(tr[j]/i)*w-((tr[j]/i-1)+(tr[j]%i!=0))*c;
            if(cc_earn>0) c_earn+=cc_earn;
        }
        if(sol<c_earn) sol=c_earn;
    }
    printf("%lld\n",sol);
    return 0;
}
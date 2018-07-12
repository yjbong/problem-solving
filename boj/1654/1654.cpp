#include <stdio.h> 
long long lan[10000]; 
int main(void){ 
    long long i,k,n,l,m,r,curn,sol; 
    scanf("%lld %lld",&k,&n); 
    for(i=0; i<k; i++) scanf("%lld",&lan[i]); 
    l=1,r=1000000000000000000;
    sol=1;
    while(l<=r){ 
        m=(l+r)/2; 
        curn=0; 
        for(i=0; i<k; i++) curn+=lan[i]/m; 
        if(curn>=n){ 
            if(sol<m) sol=m; 
            l=m+1; 
        } 
        else r=m-1; 
    } 
    printf("%lld\n",sol); 
    return 0;
}
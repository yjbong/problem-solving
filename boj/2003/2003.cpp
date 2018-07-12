#include <stdio.h>
long long num[10000];
int main(void){

    long long s,e,i,sum,sol,n,m;
    scanf("%lld %lld",&n,&m);
    for(i=0; i<n; i++) scanf("%lld",&num[i]);

    s=e=0,sum=num[0],sol=0;
    while(1){
        if(sum<m){
            e++;
            if(e>=n) break;
            sum+=num[e];
        }
        else{
            if(sum==m) sol++;
            sum-=num[s];
            s++;
            if(s>=n) break;
            if(s>e){
                e=s;
                sum=num[e];
            }
        }
    }
    if(sum==m) sol++;
    printf("%lld\n",sol);
    return 0;
}
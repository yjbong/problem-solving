#include <stdio.h>

long long totlen;
long long sol,sum;
long long dst[50000*2];
long long n;
int main(void){

    int i,s,e;
    scanf("%lld", &n);
    totlen=0;
    for(i=0; i<n; i++){
        scanf("%lld", &dst[i]);
        totlen+=dst[i];
    }
    for(i=n; i<n*2; i++) dst[i]=dst[i-n];

    sol=0;

    s=e=0;
    sum=dst[0];
    while(1){
        if(sum<=totlen/2){
            if(sol<sum) sol=sum;
            e++;
            if(e>=n*2) break;
            sum+=dst[e];
        }
        else{
            sum-=dst[s];
            s++;
            if(s>=n*2) break;
            if(s>e){
                e=s;
                if(e>=n*2) break;
                sum=dst[e];
            }
        }
    }
    printf("%lld\n", sol);
    return 0;
}
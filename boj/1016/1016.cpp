#include <stdio.h>
#define MAX 1000000
long long is_nnnum[MAX];
int main(void){

    long long i,j,k;
    long long min, max;
    long long nums, nnnums;

    scanf("%lld %lld", &min, &max);
    nums=max-min+1;
    nnnums=nums;
    for(i=0; i<nums; i++) is_nnnum[i]=1;

    i=2;
    while(nnnums>0 && i*i<=max){

        if(min%(i*i)==0) j=min;
        else j=min+(i*i-min%(i*i));

        for(k=j; k<=max; k+=(i*i)){
            if(is_nnnum[k-min]==1){
                is_nnnum[k-min]=0;
                nnnums--;
            }
        }
        i++;
    }
    printf("%lld\n", nnnums);
    return 0;
}
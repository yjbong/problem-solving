#include <stdio.h>
int main(void){
        long long sol;
        long long i, s, k;
        scanf("%lld %lld", &s, &k);
        sol=1;
        for(i=0; i<k; i++){
                if(i>=k-s%k) sol*=(s/k+1);
                else sol*=(s/k);
        }
        printf("%lld\n", sol);
        return 0;
}
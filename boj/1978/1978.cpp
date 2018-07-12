#include <stdio.h>
#include <math.h>
int is_prime(int n){
        int i, sqrt_n;
        if(n<2) return 0;
        sqrt_n=(int)sqrt(n);
        for(i=2; i<=sqrt_n; i++)
                if(n%i==0) return 0;
        return 1;
}
int main(void){
        int i, q[100], qs, sol;
        scanf("%d", &qs);
        for(i=0; i<qs; i++) scanf("%d", &q[i]);
        for(i=0, sol=0; i<qs; i++)
                if(is_prime(q[i])==1) sol++;
        printf("%d\n", sol);
        return 0;
}
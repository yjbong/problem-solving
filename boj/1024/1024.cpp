#include <stdio.h>
int main(void){
    long long i,j,n,l,start;
    scanf("%lld %lld", &n, &l);
    for(i=l; i<=100; i++){
        if((n-i*(i+1)/2)%i==0){
            start=(n-i*(i+1)/2)/i+1;
            if(start<0) continue;
            for(j=start; j<start+i; j++){
                printf("%lld", j);
                if(j==start+i-1) printf("\n");
                else printf(" ");
            }
            break;
        }
    }
    if(i>100) printf("-1\n");
    return 0;
}
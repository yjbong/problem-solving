#include <stdio.h>
int main(void){
    int n,l,c,q,sol;
    scanf("%d %d %d", &n, &l, &c);
    q=(c+1)/(l+1);
    if(q%13==0) q--;
    if(n%q==0) sol=n/q;
    else if((n%q)%13==0){
        if(n/q>=1 && q>n%q+1) sol=n/q+1;
        else sol=n/q+2;
    }
    else sol=n/q+1;
    printf("%d\n", sol);
    return 0;
}
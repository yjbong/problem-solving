#include <stdio.h>
int main(void){
    int n,sol=0;
    scanf("%d",&n);
    while(n>0){
        sol+=n%2;
        n/=2;
    }
    printf("%d\n",sol);
    return 0;
}
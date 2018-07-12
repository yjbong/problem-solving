#include <stdio.h>
#include <stdlib.h>
#define MAX 500000
long long expt[MAX];
int cmp(const void *a, const void *b){
    if(*((long long*)a)>*((long long *)b)) return 1;
    else return 0;
}
long long abs2(long long n){

    if(n>=0) return n;
    else return (-n);
}
int main(void){

    long long i, n, sol;
    long long tmp;
    scanf("%lld", &n);
    for(i=0; i<n; i++) scanf("%lld", &expt[i]);
    qsort(expt, n, sizeof(long long), cmp);
    sol=0;
    for(i=0; i<n; i++){
        tmp=abs2(expt[i]-(i+1));
        sol+=tmp;
    }
    printf("%lld\n", sol);
    return 0;
}
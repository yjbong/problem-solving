#include <stdio.h>
long long fib[41],sol;
int vip[40];
int main(void){

    int i,n,m,cur;
    fib[0]=1;
    fib[1]=1;
    for(i=2; i<=40; i++) fib[i]=fib[i-1]+fib[i-2];
    scanf("%d",&n);
    scanf("%d",&m);
    for(i=0; i<m; i++) scanf("%d",&vip[i]);
    cur=0;
    sol=1;
    for(i=0; i<m; i++){
        sol*=fib[vip[i]-1-cur];
        cur=vip[i];
    }
    sol*=fib[n-cur];
    printf("%lld\n",sol);
    return 0;
}
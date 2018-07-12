#include <cstdio>
#define SWAP(a,b,t){t=a;a=b;b=t;}
int main(void){

    long long i,j,t,isum,jsum;
    scanf("%lld %lld",&i,&j);
    if(i>j) SWAP(i,j,t);
    i--;
    if(i%2==0) isum=(i/2)*(i+1);
    else isum=((i+1)/2)*i;
    if(j%2==0) jsum=(j/2)*(j+1);
    else jsum=((j+1)/2)*j;

    printf("%lld\n",jsum-isum);
    return 0;
}
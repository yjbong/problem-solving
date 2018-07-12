#include <stdio.h>
#define MAX 1000000000000000000ll
long long fibo[100];
long long fibosum[100];
int sol[100];

int main(void){

    long long i,k,tmp;
    long long is_first;
    long long print_start;

    fibo[0]=0, fibo[1]=1;
    for(i=2; i<=88; i++)
        fibo[i]=fibo[i-1]+fibo[i-2];

    fibosum[0]=0;
    for(i=1; i<=88; i++)
        fibosum[i]=fibosum[i-1]+fibo[i];

    for(i=0; i<100; i++) sol[i]=0;

    scanf("%lld", &k);

    tmp=k;
    is_first=1;
    while(tmp>0){
        i=0;
        while(tmp>fibosum[i]) i++;
        if(is_first==1){
            print_start=i;
            is_first=0;
        }
        sol[i]=1;

        if(i>0) tmp=tmp-fibosum[i-1]-1;
        else tmp=0;
    }

    for(i=print_start; i>=1; i--){
        printf("%1d", sol[i]);
    }
    printf("\n");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
char num[10];
int tmp;
int pal_prime[100000];
int pal_primes;
int is_prime(int n){
        int i, sqrt_n;
        if(n<2) return 0;
        sqrt_n=(int)sqrt(n);
        for(i=2; i<=sqrt_n; i++)
                if(n%i==0) return 0;
        return 1;
}

void go(int dgts, int called, int cur_num){

        int i;
        num[called-1]=cur_num+'0';
        num[dgts-called]=cur_num+'0';
        if(called==dgts/2+dgts%2){
                tmp=atoi(num);
                if(is_prime(tmp)){
                        pal_prime[pal_primes]=tmp;
                        pal_primes++;
                }
                return;
        }
        else{
                for(i=0; i<=9; i++){
                        go(dgts, called+1, i);
                }
        }
}

int main(void){

        int i;
        int s, e;
        pal_prime[0]=5, pal_prime[1]=7, pal_prime[2]=11;
        pal_primes=3;

        for(i=3; i<=8; i++){
                go(i, 1, 1);
                go(i, 1, 3);
                go(i, 1, 7);
                go(i, 1, 9);
        }
        scanf("%d %d", &s, &e);
        for(i=0; i<pal_primes; i++){
                if(pal_prime[i]>=s && pal_prime[i]<=e) printf("%d\n", pal_prime[i]);
        }
        printf("-1\n");
        return 0;
}
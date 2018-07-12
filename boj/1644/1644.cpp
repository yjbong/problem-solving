#include <stdio.h>
#include <math.h>
#define MAXNUM 4000000
#define MAXPRIMES 300000

int main(void){

        int i,j;
        char is_prime[MAXNUM+1];
        int sqrt_maxnum;
        int prime[MAXPRIMES];
        int primes;
        int start_idx, end_idx, cur_sum, target_num;
        int result;

        for(i=2; i<=MAXNUM; i++) is_prime[i]=1;
        sqrt_maxnum=(int)sqrt(MAXNUM);
        for(i=2; i<=sqrt_maxnum; i++)
                for(j=i*2; j<=MAXNUM; j+=i)
                        is_prime[j]=0;

        primes=0;
        for(i=2; i<=MAXNUM; i++){
                if(is_prime[i]==1){
                        prime[primes]=i;
                        primes++;
                }
        }

        scanf("%d", &target_num);
        result=0;
        start_idx=end_idx=0;
        cur_sum=prime[start_idx];
        while(1){
                if(cur_sum>target_num){
                        cur_sum-=prime[start_idx];
                        start_idx++;
                        if(start_idx>primes-1) break;
                }
                else if(cur_sum<target_num){
                        end_idx++;
                        if(end_idx>primes-1) break;
                        cur_sum+=prime[end_idx];
                }
                else if(cur_sum==target_num){
                        result++;
                        cur_sum-=prime[start_idx];
                        start_idx++;
                        if(start_idx>primes-1) break;
                }

                if(prime[start_idx]>target_num) break;
        }

        printf("%d\n", result);
        return 0;
}
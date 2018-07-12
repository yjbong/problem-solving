#include <stdio.h>
#include <math.h>
#define MAXNUM 1000000
#define MAXPRIMES 80000

char is_prime[MAXNUM+1];
int prime[MAXPRIMES];
int primes;

int prime_bin_search(int key, int array_size){

        int left, right, mid;

        left=0;
        right=array_size-1;

        while(left<=right){

                mid=(left+right)/2;
                if(key<prime[mid]) right=mid-1;
                else if(key>prime[mid]) left=mid+1;
                else return mid;
        }

        return -1;
}

int main(void){

        int i,j,tmp;
        int sqrt_maxnum;
        int input;
        int even_num1, even_num2;
        int cur_prime1, cur_prime2;
        int result_prime[4];
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

        scanf("%d", &input);

        if(input<2*4) printf("-1\n");
        else if(input==2*4) printf("2 2 2 2\n");
        else{
                for(i=0; i<4; i++) result_prime[i]=-1;
                if(input%2==0){
                        even_num1=input/2;
                        even_num2=input/2;
                        if(even_num1%2==1){
                                even_num1--;
                                even_num2++;
                        }

                        for(i=0; i<MAXPRIMES/2; i++){
                                cur_prime1=prime[i];
                                cur_prime2=even_num1-prime[i];
                                if(cur_prime2<0) break;
                                if(prime_bin_search(cur_prime2, primes)>=0){
                                        result_prime[0]=cur_prime1;
                                        result_prime[1]=cur_prime2;
                                        break;
                                }
                        }

                        for(i=0; i<MAXPRIMES/2; i++){
                                cur_prime1=prime[i];
                                cur_prime2=even_num2-prime[i];
                                if(cur_prime2<0) break;
                                if(prime_bin_search(cur_prime2, primes)>=0){
                                        result_prime[2]=cur_prime1;
                                        result_prime[3]=cur_prime2;
                                        break;
                                }
                        }
                }

                else{
                        result_prime[0]=2;
                        result_prime[1]=3;
                        even_num1=input-2-3;
                        for(i=0; i<MAXPRIMES/2; i++){
                                cur_prime1=prime[i];
                                cur_prime2=even_num1-prime[i];
                                if(cur_prime2<0) break;
                                if(prime_bin_search(cur_prime2, primes)>=0){
                                        result_prime[2]=cur_prime1;
                                        result_prime[3]=cur_prime2;
                                        break;
                                }
                        }
                }

                for(i=0; i<4-1; i++){
                        for(j=i; j<4; j++){
                                if(result_prime[i]>result_prime[j]){
                                        tmp=result_prime[i];
                                        result_prime[i]=result_prime[j];
                                        result_prime[j]=tmp;
                                }
                        }
                }

                for(i=0; i<4; i++){
                        printf("%d", result_prime[i]);
                        if(i==3) printf("\n");
                        else printf(" ");
                }
        }

        return 0;
}
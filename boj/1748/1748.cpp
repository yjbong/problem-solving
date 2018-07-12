#include <stdio.h>
#include <math.h>
int main(void){
        long long i, N;
        long long cur_num, before_num, length;
        scanf("%lld", &N);
        length=0;
        before_num=0;
        i=1;
        while(1){
                cur_num = 9*(long long)pow(10, i-1);
                if(before_num+cur_num>N){
                        length += (N-before_num)*i;
                        break;
                }
                else{
                        length += cur_num*i;
                        before_num += cur_num;
                }
                i++;
        }
        printf("%lld\n", length);
        return 0;
}
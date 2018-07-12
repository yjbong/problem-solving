#include <stdio.h>
#define MAX 2097152
long long sum[MAX];
long long nums, near_pow;
long long changes, queries;

void change_tree(long long ch_pos, long long ch_val){

        long long tmp;
        tmp=near_pow-1+ch_pos;
        sum[tmp]=ch_val;
        while(tmp>1){
                tmp/=2;
                sum[tmp]=sum[tmp*2]+sum[tmp*2+1];
        }
}

long long get_subsum(long long start, long long end){

        long long cur_sum;
        cur_sum=0;

        start=near_pow+start-1;
        end=near_pow+end-1;

        while(1){
                if(start==end){
                        cur_sum+=sum[start];
                        break;
                }

                else if(start>end) break;

                if(start%2==0) start/=2;
                else{
                        cur_sum+=sum[start];
                        start=(start+1)/2;
                }

                if(end%2==1) end/=2;
                else{
                        cur_sum+=sum[end];
                        end=(end-1)/2;
                }
        }

        return cur_sum;
}

int main(void){

        long long i, a, b, c;
        scanf("%lld %lld %lld", &nums, &changes, &queries);
        near_pow=1;

        while(near_pow<nums){
                near_pow*=2;
        }

        for(i=near_pow; i<near_pow+nums; i++) scanf("%lld", &sum[i]);
        for(i=near_pow+nums; i<near_pow*2; i++) sum[i]=0;
        for(i=near_pow-1; i>=1; i--) sum[i]=sum[i*2]+sum[i*2+1];

        for(i=0; i<changes+queries; i++){

                scanf("%lld %lld %lld", &a, &b, &c);
                if(a==1) change_tree(b, c);
                else if(a==2){
                        printf("%lld\n", get_subsum(b, c));
                }
        }

        return 0;
}
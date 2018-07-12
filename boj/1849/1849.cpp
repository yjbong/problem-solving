#include <stdio.h>
#include <stdio.h>
#define MAXNUM 100000
int AI[MAXNUM+1];
int I[MAXNUM+1];
int B[262144+1];
int nums;
int near_pow;

void update_B(int put_idx){

        int tmp;
        tmp=put_idx;
        B[tmp]=0;
        while(tmp>1){
                tmp/=2;
                B[tmp]=B[tmp*2]+B[tmp*2+1];
        }
}

int blank_pos(int target_num){

        int cur_idx;
        cur_idx=1;
        while(1){
                if(B[cur_idx]>target_num) cur_idx*=2;
                else if(B[cur_idx]<target_num){
                        target_num-=B[cur_idx];
                        cur_idx++;
                }
                else{
                        if(cur_idx>=near_pow) break;
                        else cur_idx*=2;
                }
        }
        return cur_idx;
}

int main(void){

        int i, j, nums, put_idx;
        scanf("%d", &nums);
        for(i=1; i<=nums; i++) scanf("%d", &AI[i]);
        for(i=1; i<=nums; i++) I[i]=0;

        near_pow=1;
        while(near_pow<nums) near_pow*=2;

        for(i=near_pow; i<near_pow*2; i++) B[i]=1;
        for(i=near_pow-1; i>=1; i--) B[i]=B[i*2]+B[i*2+1];

        for(i=1; i<=nums; i++){
                put_idx=blank_pos(AI[i]+1);
                I[put_idx-near_pow+1]=i;
                update_B(put_idx);
        }

        for(i=1; i<=nums; i++) printf("%d\n", I[i]);
        return 0;
}
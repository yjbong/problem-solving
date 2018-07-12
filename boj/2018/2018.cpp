#include <stdio.h>
#include <math.h>
#define MAXNUM 10000000

int main(void){

        int i,j;
        int start, end, cur_sum, target;
        int sol;

        scanf("%d", &target);

        sol=0;
        start=end=1;
        cur_sum=1;
        while(1){
                if(cur_sum>target){
                        cur_sum-=start;
                        start++;
                        if(start>target) break;
                }
                else if(cur_sum<target){
                        end++;
                        if(end>MAXNUM) break;
                        cur_sum+=end;
                }
                else if(cur_sum==target){
                        sol++;
                        cur_sum-=start;
                        start++;
                        if(start>target) break;
                }

                if(start>target) break;
        }

        printf("%d\n", sol);
        return 0;
}
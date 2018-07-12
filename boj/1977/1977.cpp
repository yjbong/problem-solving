#include <stdio.h>
int pow_num[100+1];
int main(void){

        int i, start, end;
        int start_idx, end_idx, sum;

        for(i=0; i<=100; i++) pow_num[i]=i*i;
        scanf("%d %d", &start, &end);

        for(i=0; i<=100; i++){
                if(pow_num[i]>=start){
                        start_idx=i;
                        break;
                }
        }

        for(i=100; i>=0; i--){
                if(pow_num[i]<=end){
                        end_idx=i;
                        break;
                }
        }

        if(start_idx<=end_idx){
                for(i=start_idx, sum=0; i<=end_idx; i++) sum+=pow_num[i];
                printf("%d\n", sum);
                printf("%d\n", pow_num[start_idx]);
        }

        else printf("-1\n");

        return 0;
}
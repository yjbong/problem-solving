#include <stdio.h>
#define MAX_ROWS 200
#define MAX_COLS 200
#define MINUS_INF -1000000000000000000
long long board[MAX_ROWS][MAX_COLS];
int main(void){

        long long i, j, k, rows, cols;
        long long max_sum, cur_sum;
        long long cur_list[MAX_COLS];
        long long is_nonnega;
        scanf("%lld %lld", &rows, &cols);
        for(i=0; i<rows; i++){
                for(j=0; j<cols; j++){
                        scanf("%lld", &board[i][j]);
                        if(i>0) board[i][j]+=board[i-1][j];
                }
        }

        max_sum=MINUS_INF;
        is_nonnega=0;
        for(i=0; i<rows; i++){
                for(j=i; j<rows; j++){
                        for(k=0; k<cols; k++){
                                cur_list[k]=board[j][k];
                                if(i>0) cur_list[k]-=board[i-1][k];
                        }

                        cur_sum=0;
                        for(k=0; k<cols; k++){
                                if(cur_list[k]>=0){
                                        cur_sum+=cur_list[k];
                                        is_nonnega=1;
                                }

                                else{
                                        if(is_nonnega==0){
                                                if(max_sum<cur_list[k]) max_sum=cur_list[k];
                                        }

                                        else if(max_sum<cur_sum) max_sum=cur_sum;

                                        if(cur_sum+cur_list[k]<0) cur_sum=0;
                                        else cur_sum=cur_sum+cur_list[k];
                                }
                        }

                        if(is_nonnega==1 && max_sum<cur_sum) max_sum=cur_sum;
                }
        }

        printf("%lld\n", max_sum);
        return 0;
}
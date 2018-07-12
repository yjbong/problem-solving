#include <stdio.h>
#define MAXNUM 1000
#define MAXDIGIT 4
int main(void){

        int i, j, dst, input, tmp, is_add;
        int result[MAXNUM+1];
        int cur_digit[MAXDIGIT], cur_digits;
        for(i=1; i<=9; i++) result[i]=i;

        for(i=10; i<=MAXNUM; i++){

                tmp=i;
                cur_digits=0;
                while(tmp>0){
                        cur_digit[cur_digits]=tmp%10;
                        cur_digits++;
                        tmp/=10;
                }

                is_add=1;
                dst=cur_digit[1]-cur_digit[0];

                for(j=2; j<cur_digits; j++){
                        if(cur_digit[j]-cur_digit[j-1]!=dst){
                                is_add=0;
                                break;
                        }
                }

                if(is_add) result[i]=result[i-1]+1;
                else result[i]=result[i-1];
        }

        scanf("%d", &input);
        printf("%d\n", result[input]);

        return 0;
}
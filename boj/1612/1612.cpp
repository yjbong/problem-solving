#include <stdio.h>
int main(void){
        long long number, ones, i, j;
        long long not_one_part, last_digit;
        long long multiple[10][10];

        for(i=0; i<10; i++)
                for(j=0; j<10; j++)
                        multiple[i][j] = i*j;

        scanf("%lld", &number);

        not_one_part = number;
        last_digit = number % 10;
        if(last_digit%2==0 || last_digit==5) printf("-1\n");
        else{
                ones = 0;
                do{
                        if(not_one_part % 10 == 1){
                                ones++;
                                not_one_part /= 10;
                        }

                        else{
                                for(i=0; i<10; i++){
                                        if((not_one_part%10 + multiple[last_digit][i]) % 10 == 1){
                                                not_one_part += number * i;
                                                break;
                                        }
                                }
                        }

                }while(not_one_part != 0);

                printf("%lld\n", ones);
        }

        return 0;
}
#include <stdio.h>
#include <math.h>
void itoa2(int num, char* tmp){

        int i;
        int tmp_len;
        char tmp_char;
        tmp_len=0;
        while(num>0){
                tmp[tmp_len]=num % 10+'0';
                num /= 10;
                tmp_len++;
        }

        for(i=0; i<tmp_len/2; i++){
                tmp_char = tmp[i];
                tmp[i] = tmp[tmp_len-1-i];
                tmp[tmp_len-1-i]=tmp_char;
        }
        tmp[tmp_len]='\0';
}

int main(void){

        long long i, N, k, digits;
        long long accum[10];

        long long num_idx, digit_idx;
        long long target_num;
        long long cur_num, before_num, length;
        char tmp[20];
        accum[0]=0;
        for(i=1; i<=9; i++){
                accum[i]=accum[i-1]+9*i*(long long)pow(10, i-1);
        }

        scanf("%lld %lld", &N, &k);
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

        if(length<k) printf("-1\n");

        else{
                for(i=0; i<=9; i++){
                        if(k<=accum[i]){
                                digits=i;
                                break;
                        }
                }

                k-=accum[digits-1];

                num_idx=k/digits;
                digit_idx=k%digits;

                if(digit_idx==0){
                        digit_idx=digits;
                        num_idx--;
                }

                target_num=(long long)pow(10, digits-1)+num_idx;
                itoa2(target_num, tmp);
                printf("%c\n", tmp[digit_idx-1]);
        }

        return 0;
}
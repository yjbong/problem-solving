#include <stdio.h>
#include <string.h>
#define MAXLEN 1000000
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
        int i, num_len;
        char num[MAXLEN+1];
        int cur_num, steps;
        scanf("%s", num);
        num_len=strlen(num);

        if(num_len==1){
                steps=0;
                cur_num=num[0]-'0';
        }
        else{
                steps=0;
                do{
                        cur_num=0;
                        num_len=strlen(num);
                        for(i=0; i<num_len; i++){
                                cur_num+=(num[i]-'0');
                        }
                        steps++;
                        itoa2(cur_num, num);
                }while(cur_num>=10);
        }

        printf("%d\n", steps);
        if(cur_num%3==0) printf("YES\n");
        else printf("NO\n");

        return 0;
}
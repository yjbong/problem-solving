#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int reverse(int n){

        int i, tmp_len;
        char tmp[10];
        char tmp_char;
        itoa2(n, tmp);
        tmp_len=strlen(tmp);
        for(i=0; i<tmp_len/2; i++){
                tmp_char=tmp[i];
                tmp[i]=tmp[tmp_len-1-i];
                tmp[tmp_len-1-i]=tmp_char;
        }
        return atoi(tmp);
}

int main(void){

        int x, y;
        scanf("%d %d", &x,&y);
        printf("%d\n", reverse(reverse(x)+reverse(y)));
        return 0;
}
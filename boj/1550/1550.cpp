#include <stdio.h>
#include <string.h>
#define MAX_HEX_DIGIT 6
int main(void){

        char hex_num[MAX_HEX_DIGIT+1];
        int i, dec_num, hex_num_len;
        scanf("%s", hex_num);
        hex_num_len=strlen(hex_num);
        dec_num=0;
        for(i=0; i<hex_num_len; i++){
                dec_num*=16;
                if(hex_num[i]>='A' && hex_num[i]<='F')
                        dec_num+=hex_num[i]-'A'+10;
                else if(hex_num[i]>='0' && hex_num[i]<='9')
                        dec_num+=hex_num[i]-'0';
        }
        printf("%d\n", dec_num);
        return 0;
}
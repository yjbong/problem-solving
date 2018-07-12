#include <stdio.h>
#include <string.h>
#define MAXLEN 10000
int main(void){

        char str_num[2][MAXLEN+1];
        long long i, j, dec_num[2], cur_len;
        scanf("%s %s", str_num[0], str_num[1]);

        for(i=0; i<2; i++){
                cur_len=strlen(str_num[i]);
                dec_num[i]=0;
                for(j=0; j<cur_len; j++)
                        dec_num[i]+=str_num[i][j]-'0';
        }
        printf("%lld\n", dec_num[0]*dec_num[1]);
        return 0;
}
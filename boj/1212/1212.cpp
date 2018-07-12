#include <stdio.h>
#include <string.h>
#define MAXLEN 333334
char octal[MAXLEN+1];
int octal_len;
char print_bin[8][4]={"000","001","010","011","100","101","110","111"};
char print_first_bin[8][4]={"0","1","10","11","100","101","110","111"};

int main(void){

        int i;
        scanf("%s", octal);
        octal_len=strlen(octal);
        for(i=0; i<octal_len; i++){
                if(i==0) printf("%s", print_first_bin[octal[i]-'0']);
                else printf("%s", print_bin[octal[i]-'0']);
        }
        printf("\n");
        return 0;
}
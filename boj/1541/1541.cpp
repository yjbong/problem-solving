#include <stdio.h>
#include <string.h>
char str[51];
int main(void){

    int i, minus, cur_num, sol;
    scanf("%s", str);
    minus=0;
    cur_num=0;
    sol=0;
    for(i=0; i<strlen(str); i++){
        if(str[i]>='0' && str[i]<='9'){
            cur_num*=10;
            cur_num+=str[i]-'0';
        }
        if(str[i]=='+' || str[i]=='-' || i==strlen(str)-1){
            if(minus==1) sol-=cur_num;
            else sol+=cur_num;
            cur_num=0;
            if(str[i]=='-') minus=1;
        }
    }
    printf("%d\n", sol);
    return 0;
}
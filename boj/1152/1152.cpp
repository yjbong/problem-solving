#include <stdio.h>
#include <string.h>
#include <ctype.h>
char line[1000001];
int main(void){

    int i,len,sol;
    int bef_blank;
    gets(line);
    len=strlen(line);
    bef_blank=1;
    sol=0;
    for(i=0; i<len; i++){
        if(bef_blank){
            if(isalpha(line[i])){
                sol++;
                bef_blank=0;
            }
        }
        else{
            if(line[i]==' '){
                bef_blank=1;
            }
        }
    }
    printf("%d\n",sol);
    return 0;
}
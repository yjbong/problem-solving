#include <stdio.h>
#include <string.h>
char line[30001];
int linelen;
char key[30001];
int keylen;
int main(void){
    int i;
    char curchar;
    gets(line);
    gets(key);
    linelen=strlen(line);
    keylen=strlen(key);
    for(i=0; i<linelen; i++){
        if(line[i]==' ') printf(" ");
        else{
            curchar=line[i]-(key[i%keylen]-'a'+1);
            if(curchar<'a') curchar+=26;
            printf("%c", curchar);
        }
    }
    printf("\n");
    return 0;
}
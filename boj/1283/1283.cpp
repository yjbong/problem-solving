#include <stdio.h>
#include <string.h>
int is_set[26];
char line[200];

int validchar(char c){

    if(c>='a' && c<='z'){
        if(is_set[c-'a']==0){
            is_set[c-'a']=1;
            return 1;
        }
        else return 0;
    }
    else if(c>='A' && c<='Z'){
        if(is_set[c-'A']==0){
            is_set[c-'A']=1;
            return 1;
        }
        else return 0;
    }
    return 0;
}

int main(void){

    int i,j,n;
    int optioncharidx,beforeblank,usefirstchar;
    for(i=0; i<26; i++) is_set[i]=0;

    scanf("%d\n", &n);
    for(i=0; i<n; i++){
        fgets(line, 200, stdin);
        line[strlen(line)-1]='\0';

        optioncharidx=-1;
        usefirstchar=0;
        beforeblank=1;
        for(j=0; j<strlen(line); j++){
            if(line[j]!=' '){
                if(j==0 || beforeblank==1){
                    beforeblank=0;
                    if(validchar(line[j])==1){
                        optioncharidx=j;
                        usefirstchar=1;
                        break;
                    }
                }
            }
            else beforeblank=1;
        }

        if(usefirstchar==0){
           for(j=0; j<strlen(line); j++){
               if(validchar(line[j])==1){
                   optioncharidx=j;
                   break;
               }
           }
        }
        if(optioncharidx<0) printf("%s\n", line);
        else{
            for(j=0; j<strlen(line); j++){
                if(j==optioncharidx) printf("[%c]", line[j]);
                else printf("%c", line[j]);
            }
            printf("\n");
        }
    }
    return 0;
}
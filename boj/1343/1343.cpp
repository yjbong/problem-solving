#include <stdio.h>
#include <string.h>
char b[51];
int main(void){

    int i,j;
    int curb,curstart,as,bs;
    int ok;
    scanf("%s", b);

    curb=0;
    ok=1;
    curstart=0;
    for(i=0; i<strlen(b); i++){
        if(b[i]=='X') curb++;
        else if(b[i]=='.'){
            if(curb%2==0){
                as=curb/4*4;
                bs=curb-as;
                for(j=curstart; j<curstart+as; j++) b[j]='A';
                for(; j<curstart+as+bs; j++) b[j]='B';
            }
            else{
                ok=0;
                break;
            }
            curstart=i+1;
            curb=0;
        }
    }


    if(b[strlen(b)-1]=='X'){
        if(curb%2==0){
            as=curb/4*4;
            bs=curb-as;
            for(j=curstart; j<curstart+as; j++) b[j]='A';
            for(; j<curstart+as+bs; j++) b[j]='B';
        }
        else ok=0;
    }

    if(ok==0) printf("-1\n");
    else printf("%s\n", b);

    return 0;
}
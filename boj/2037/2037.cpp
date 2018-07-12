#include <stdio.h>
#include <string.h>
char schar[]="ADGJMPTW";

int main(void){

    int i,j,old_j,p,w,scharlen;
    int time;
    char curchar;
    scanf("%d %d\n", &p, &w);
    scharlen=strlen(schar);
    time=0;
    old_j=-1;
    while(scanf("%c", &curchar)==1){

        if(curchar=='\n') break;

        else if(curchar==' '){
            time+=p;
            old_j=-1;
        }
        else{
            j=0;
            while(j<scharlen && curchar>=schar[j]) j++;
            j--;
            time+=(curchar-schar[j]+1)*p;
            if(old_j==j) time+=w;
            old_j=j;
        }
    }
    printf("%d\n", time);
    return 0;
}
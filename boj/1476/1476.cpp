#include <stdio.h>
int main(void){

    int e,s,m,curnum;
    scanf("%d %d %d",&e,&s,&m);
    e--,s--,m--;

    curnum=e;
    while(1){
        if(curnum%28==s && curnum%19==m) break;
        curnum+=15;
    }
    printf("%d\n", curnum+1);
    return 0;
}
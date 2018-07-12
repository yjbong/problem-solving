#include <stdio.h>
#include <string.h>
char a[51];
char b[51];
int main(void){

    int i,j,alen,blen;
    int cur_diff, min_diff;
    scanf("%s", a);
    scanf("%s", b);

    alen=strlen(a);
    blen=strlen(b);

    min_diff=1000000000;
    for(i=0; i<=blen-alen; i++){
        cur_diff=0;
        for(j=i; j<i+alen; j++) if(b[j]!=a[j-i]) cur_diff++;
        if(min_diff>cur_diff) min_diff=cur_diff;
    }
    printf("%d\n", min_diff);
}
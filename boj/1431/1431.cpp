#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char name[1000][51];
int cmp(const void *a, const void *b){

    int i;
    int alen,blen,asum,bsum;
    char curchar;
    alen=strlen((char*)a);
    blen=strlen((char*)b);
    if(alen>blen) return 1;
    else if(alen==blen){
        asum=0;
        for(i=0; i<alen; i++){
            curchar=*((char*)a+i);
            if(curchar>='0' && curchar<='9'){
                asum+=curchar-'0';
            }
        }
        bsum=0;
        for(i=0; i<blen; i++){
            curchar=*((char*)b+i);
            if(curchar>='0' && curchar<='9'){
                bsum+=curchar-'0';
            }
        }
        if(asum>bsum) return 1;
        else if(asum==bsum){
            if(strcmp((char*)a, (char*)b)>0) return 1;
        }
    }
    return 0;
}

int main(void){

    int i,n;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%s", name[i]);
    qsort(name, n, sizeof(char)*51, cmp);

    for(i=0; i<n; i++) printf("%s\n", name[i]);
    return 0;
}
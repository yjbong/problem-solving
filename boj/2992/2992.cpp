#include <stdio.h>
#include <string.h>
#define SWAP(a,b,tmp){tmp=a;a=b;b=tmp;}
char num[10];
int main(void){
    int i,j,k,len,min_idx;
    char tmp;
    scanf("%s", num);
    len=strlen(num);
    for(i=len-1; i>=0; i--){
        min_idx=-1;
        for(j=i+1; j<len; j++){
             if(num[j]>num[i]){
                  if(min_idx<0 || num[min_idx]>num[j]) min_idx=j;
             }
        }
        if(min_idx>=0){
            SWAP(num[i],num[min_idx],tmp);
            for(j=i+1; j<len-1; j++){
                for(k=j+1; k<len; k++){
                    if(num[j]>num[k]) SWAP(num[j],num[k],tmp);
                }
            }
            break;
        }
    }
    if(i<0) printf("0\n");
    else printf("%s\n", num);
    return 0;
}
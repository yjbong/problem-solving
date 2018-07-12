#include <stdio.h>
#include <string.h>
#define SWAP(a,b,tmp){tmp=a;a=b;b=tmp;}
int main(void){

    int i,j,len;
    char n[11],tmp;
    scanf("%s", n);
    len=strlen(n);
    for(i=0; i<len-1; i++)
      for(j=i+1; j<len; j++)
        if(n[i]<n[j]) SWAP(n[i],n[j],tmp);
    printf("%s\n", n);
    return 0;
}
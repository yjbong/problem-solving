#include <stdio.h>
#include <string.h>
int main(void){
    char num[20];
    int len;
    int a,b,i,j;
    scanf("%s", num);
    len=strlen(num);
    for(i=1; i<len; i++){
        for(j=0,a=1; j<i; j++) a*=(num[j]-'0');
        for(j=i,b=1; j<len; j++) b*=(num[j]-'0');
        if(a==b) break;
    }
    if(i==len) printf("NO\n");
    else printf("YES\n");
    return 0;
}
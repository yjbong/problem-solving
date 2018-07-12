#include <stdio.h>
#include <string.h>
char as[100],bs[100];
int a[100],b[100],c;
int main(void){

    int i,j,flag;
    scanf("%s %s",as,bs);
    for(i=0; i<100; i++) a[i]=0,b[i]=0;
    for(i=strlen(as)-1,j=0; i>=0; i--,j++) a[j]=as[i]-'0';
    for(i=strlen(bs)-1,j=0; i>=0; i--,j++) b[j]=bs[i]-'0';
    for(i=0,c=0; i<100; i++){
        a[i]=a[i]+b[i]+c;
        if(a[i]>=2) a[i]-=2,c=1;
        else c=0;
    }

    flag=0;
    for(i=99; i>=0; i--){
        if(a[i]>0) flag=1;
        if(flag) printf("%d",a[i]);
    }
    if(!flag) printf("0");
    printf("\n");
    return 0;
}
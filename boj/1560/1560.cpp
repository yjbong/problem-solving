#include <stdio.h>
#include <string.h>
int a[101],b[101];
char n[101];
void minus(int a[],int b[]){ //a=a-b

    int i,j;
    for(i=0; i<=100; i++){
        a[i]=a[i]-b[i];
        j=i;
        while(a[j]<0){
            a[j]=a[j]+10;
            j++;
            a[j]--;
        }
    }
}
void plus(int a[],int b[]){ //a=a+b

    int i,j;
    for(i=0; i<=100; i++){
        a[i]=a[i]+b[i];
        j=i;
        while(a[j]>9){
            a[j]=a[j]-10;
            j++;
            a[j]++;
        }
    }
}
void print(int a[]){

    int i,is_nonzero=0;
    for(i=100; i>=0; i--){
        if(is_nonzero||a[i]>0){
            printf("%d",a[i]);
            is_nonzero=1;
        }
    }
    if(!is_nonzero) printf("0");
    printf("\n");
}
int main(void){

    int i,j;
    for(i=0; i<=100; i++) a[i]=0;
    scanf("%s",n);
    if(strcmp(n,"1")==0) printf("1\n");
    else{
        for(i=strlen(n)-1,j=0; i>=0; i--,j++) a[j]=n[i]-'0';
        b[0]=1;
        for(i=1; i<=100; i++) b[i]=0;
        minus(a,b);
        for(i=0; i<=100; i++) b[i]=a[i];
        plus(a,b);
        print(a);
    }
    return 0;
}
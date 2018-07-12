#include <stdio.h>
int main(void){

    int a,b,n,cnt;
    scanf("%d %d %d",&a,&b,&n);
    a=a%b;

    cnt=1;
    while(1){
        a=a*10;
        if(cnt==n){
            printf("%d\n",a/b);
            break;
        }
        a=a%b;
        cnt++;
    }
    return 0;
}
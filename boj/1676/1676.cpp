#include<stdio.h>
int main(void){
        int n,s;
        scanf("%d",&n);
        s=0;
        while(n>0)s+=n/5,n/=5;
        printf("%d\n",s);
        return 0;
}
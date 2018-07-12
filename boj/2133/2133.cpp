#include <stdio.h>
int d[16];
int main(void){
        int i,n;
        d[1]=3, d[2]=11;
        for(i=3; i<=15; i++) d[i]=d[i-1]*3+(d[i-1]-d[i-2]);
        scanf("%d",&n);
        if(n%2==1) printf("0\n");
        else printf("%d\n",d[n/2]);
        return 0;
}
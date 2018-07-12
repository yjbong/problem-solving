#include<stdio.h>
int main(void){
        int n,f;
        scanf("%d %d", &n, &f);
        printf("%02d\n", (n/100*100)%f==0?0:f-(n/100*100)%f);
        return 0;
}
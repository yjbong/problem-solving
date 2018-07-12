#include <stdio.h>
int main(void){
        int n, tmp;
        scanf("%d", &n);
        tmp=10;
        while(n>tmp){
                if(n%tmp>=tmp/10*5) n+=tmp;
                n=n/tmp*tmp;
                tmp*=10;
        }
        printf("%d\n", n);
        return 0;
}
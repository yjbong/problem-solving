#include <stdio.h>
int main(void){

        int i, n, tmp, cycles[100];
        for(i=0; i<=99; i++){
                cycles[i]=0;
                tmp=i;
                do{
                        tmp=(tmp%10)*10+(tmp/10+tmp%10)%10;
                        cycles[i]++;

                }while(tmp!=i);
        }
        scanf("%d", &n);
        printf("%d\n", cycles[n]);
        return 0;
}
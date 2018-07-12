#include <stdio.h>
#define MAXNUM 40
int main(void){
        int i,cases,cur_fibo;
        int fibo[MAXNUM+1][2];
        fibo[0][0]=1, fibo[0][1]=0;
        fibo[1][0]=0, fibo[1][1]=1;
        for(i=2; i<=MAXNUM; i++){
                fibo[i][0]=fibo[i-1][0]+fibo[i-2][0];
                fibo[i][1]=fibo[i-1][1]+fibo[i-2][1];
        }
        scanf("%d", &cases);
        while(cases--){
                scanf("%d", &cur_fibo);
                printf("%d %d\n", fibo[cur_fibo][0], fibo[cur_fibo][1]);
        }
        return 0;
}
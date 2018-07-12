#include <stdio.h>
#include <math.h>
int main(void){
        int N, tot_sings, cur_sings;
        scanf("%d", &N);
        tot_sings=0;
        while(N>0){
                cur_sings=floor((sqrt(8.0*N+1)-1)/2);
                N-=cur_sings*(cur_sings+1)/2;
                tot_sings+=cur_sings;
        }
        printf("%d\n", tot_sings);
        return 0;
}
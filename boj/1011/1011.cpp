#include <stdio.h>
#include <math.h>
int main(void){

        int cases;
        unsigned int dst, sqrt_dst, min_step;
        unsigned int x,y;
        scanf("%d", &cases);
        while(cases--){
                scanf("%u %u", &x, &y);
                dst=y-x;
                sqrt_dst=(unsigned int)sqrt(dst);
                if(dst-sqrt_dst*sqrt_dst==0) min_step=2*sqrt_dst-1;
                else if((sqrt_dst+1)*(sqrt_dst+1)-dst<sqrt_dst+1) min_step=2*sqrt_dst+1;
                else min_step=2*sqrt_dst;

                printf("%u\n", min_step);
        }
        return 0;
}
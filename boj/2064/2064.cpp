#include <stdio.h>
#define MAXNUM 1000
long long input[4];
long long ip[MAXNUM];
long long ips;
long long print_sol[4];
long long print_mask[4];
int main(void){
        long long i,j;
        long long sol, tmp, mask;
        scanf("%lld", &ips);
        for(i=0; i<ips; i++){
                scanf("%lld.%lld.%lld.%lld", &input[0], &input[1], &input[2], &input[3]);

                ip[i]=0;
                for(j=0; j<4; j++){
                        ip[i]*=256;
                        ip[i]+=input[j];
                }
        }

        if(ips==1){
                printf("%lld.%lld.%lld.%lld\n", input[0], input[1], input[2], input[3]);
                printf("255.255.255.255\n");
        }

        else{
                mask=0;
                for(i=1; i<ips; i++){
                        tmp=ip[i-1]^ip[i];
                        mask=mask|tmp;
                }

                tmp=1;
                while(tmp<=mask) tmp*=2;

                mask=tmp-1;
                mask=~(mask);
                sol=ip[0]&mask;

                i=3;
                while(i>=0){
                        print_sol[i]=sol&(0x00000000000000FF);
                        sol>>=8;
                        i--;
                }
                printf("%lld.%lld.%lld.%lld\n", print_sol[0], print_sol[1], print_sol[2], print_sol[3]);

                i=3;
                while(i>=0){
                        print_mask[i]=mask&(0x00000000000000FF);
                        mask>>=8;
                        i--;
                }
                printf("%lld.%lld.%lld.%lld\n", print_mask[0], print_mask[1], print_mask[2], print_mask[3]);
        }
        return 0;
}
#include <stdio.h>
#define MAX 50
int sol[MAX];
int main(void){

        int i, j, n, sol_digits, carry, tmp, tot_digits;
        scanf("%d", &n);
        for(i=0; i<MAX; i++) sol[i]=0;

        sol[0]=1;
        sol_digits=1, carry=0;
        for(i=0; i<n; i++){
                for(j=0; j<sol_digits; j++){
                        sol[j]=sol[j]*5+carry;
                        carry=0;
                        if(sol[j]>=10000){
                                carry=sol[j]/10000;
                                sol[j]=sol[j]%10000;
                                if(j==sol_digits-1) sol_digits++;
                        }
                }
        }

        tot_digits=0;
        tmp=sol[sol_digits-1];
        while(tmp>0){
                tmp/=10;
                tot_digits++;
        }
        tot_digits+=(sol_digits-1)*4;

        printf("0.");
        for(i=0; i<n-tot_digits; i++) printf("0");

        for(i=sol_digits-1; i>=0; i--){
                if(i==sol_digits-1) printf("%d", sol[i]);
                else printf("%04d", sol[i]);
        }
        printf("\n");
        return 0;
}
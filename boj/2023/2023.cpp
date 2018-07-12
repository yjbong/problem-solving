#include <stdio.h>
#include <math.h>
int amaze[9][100];
int amazes[9];
int is_prime(int n){
        int i, sqrt_n;
        if(n<2) return 0;
        sqrt_n=(int)sqrt(n);
        for(i=2; i<=sqrt_n; i++)
                if(n%i==0) return 0;
        return 1;
}

int main(void){
        int i,j,n;
        amaze[1][0]=2, amaze[1][1]=3, amaze[1][2]=5, amaze[1][3]=7;
        amazes[1]=4;
        for(i=2; i<=8; i++) amazes[i]=0;
        for(i=2; i<=8; i++){
                for(j=0; j<amazes[i-1]; j++){
                        if(is_prime(amaze[i-1][j]*10+1)){
                                amaze[i][amazes[i]]=amaze[i-1][j]*10+1;
                                amazes[i]++;
                        }
                        if(is_prime(amaze[i-1][j]*10+3)){
                                amaze[i][amazes[i]]=amaze[i-1][j]*10+3;
                                amazes[i]++;
                        }
                        if(is_prime(amaze[i-1][j]*10+7)){
                                amaze[i][amazes[i]]=amaze[i-1][j]*10+7;
                                amazes[i]++;
                        }
                        if(is_prime(amaze[i-1][j]*10+9)){
                                amaze[i][amazes[i]]=amaze[i-1][j]*10+9;
                                amazes[i]++;
                        }
                }
        }

        scanf("%d", &n);
        for(i=0; i<amazes[n]; i++) printf("%d\n", amaze[n][i]);

        return 0;
}
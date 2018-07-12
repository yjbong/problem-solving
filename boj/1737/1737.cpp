#include <stdio.h>
#include <math.h>
#define DIVNUM 1000000000000000000
#define PI_NUM 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
int main(void){
        long long i,j,bound,input;
        long long pibo[1000+1][400];
        for(i=0; i<=1000; i++){
                bound=(long long)floor((double)i/PI_NUM);
                pibo[i][bound]=1;
                for(j=bound-1; j>=0; j--){
                        pibo[i][j]=(pibo[i-1][j]+pibo[i][j+1])%DIVNUM;
                }
        }
        scanf("%lld", &input);
        printf("%lld\n", pibo[input][0]);
        return 0;
}
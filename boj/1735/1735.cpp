#include <stdio.h>
#define SWAP(a,b,tmp) {tmp=a; a=b; b=tmp;}
long long gcd(long long a, long long b){

        long long tmp;
        if(a<b) SWAP(a,b,tmp);
        while(b>0){
                a=a%b;
                SWAP(a,b,tmp);
        }
        return a;
}

int main(void){

        long long i;
        long long bunja[2], bunmo[2];
        long long cur_gcd;
        long long result_bunja, result_bunmo;

        scanf("%lld %lld", &bunja[0], &bunmo[0]);
        scanf("%lld %lld", &bunja[1], &bunmo[1]);

        for(i=0; i<=1; i++){
                cur_gcd=gcd(bunja[i], bunmo[i]);
                bunja[i]/=cur_gcd;
                bunmo[i]/=cur_gcd;
        }

        result_bunmo=gcd(bunmo[0], bunmo[1])*bunmo[0]*bunmo[1];
        result_bunja=bunja[0]*(result_bunmo/bunmo[0])+bunja[1]*(result_bunmo/bunmo[1]);

        cur_gcd=gcd(result_bunja, result_bunmo);
        result_bunja/=cur_gcd;
        result_bunmo/=cur_gcd;

        printf("%lld %lld\n", result_bunja, result_bunmo);

        return 0;
}
#include <stdio.h>
#define MAXTABS 500000
long long tab[MAXTABS];
int main(void){

        long long i;
        long long tabs;
        long long sol;
        scanf("%lld", &tabs);
        for(i=0; i<tabs; i++) scanf("%lld", &tab[i]);

        sol=0;
        for(i=0; i<tabs; i++){
                if(i==tabs-1) sol+=tab[i];
                else sol+=tab[i]-1;
        }
        printf("%lld\n", sol);
        return 0;
}
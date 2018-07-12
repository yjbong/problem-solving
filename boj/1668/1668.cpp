#include <stdio.h>
#define MAX_TROPI 1000000
int tropi[MAX_TROPI];
int main(void){

        int i;
        int lmax, rmax;
        int lvis, rvis;
        int tropies;
        scanf("%d", &tropies);
        for(i=0; i<tropies; i++)
                scanf("%d", &tropi[i]);

        lmax=0, lvis=0;
        for(i=0; i<tropies; i++){
                if(tropi[i]>lmax){
                        lmax=tropi[i];
                        lvis++;
                }
        }

        rmax=0, rvis=0;
        for(i=tropies-1; i>=0; i--){
                if(tropi[i]>rmax){
                        rmax=tropi[i];
                        rvis++;
                }
        }
        printf("%d\n%d\n", lvis, rvis);
        return 0;
}
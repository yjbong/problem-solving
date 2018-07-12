#include <stdio.h>
#define MAX_TILES 30

int main(void){

        int i, input;
        int codes[MAX_TILES+1];
        int unique_codes[MAX_TILES+1];
        int result;
        codes[0]=0, codes[1]=1, codes[2]=3;

        for(i=3; i<=MAX_TILES; i++){
                codes[i]=codes[i-1]+codes[i-2]*2;
        }

        unique_codes[0]=0, unique_codes[1]=1, unique_codes[2]=3, unique_codes[3]=1, unique_codes[4]=5;
        for(i=5; i<=MAX_TILES; i++){
                unique_codes[i]=unique_codes[i-2]+unique_codes[i-4]*2;
        }

        scanf("%d", &input);
        result=codes[input]-(codes[input]-unique_codes[input])/2;
        printf("%d\n", result);
        return 0;
}
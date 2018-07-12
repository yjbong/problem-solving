#include <stdio.h>
#include <string.h>

int main(void){

    int i;
    char num[10];
    int frq[9],maxfrq,curfrq;
    for(i=0; i<9; i++) frq[i]=0;
    scanf("%s", num);
    for(i=0; i<strlen(num); i++){
        if(num[i]=='9') frq[6]++;
        else frq[num[i]-'0']++;
    }

    maxfrq=0;
    for(i=0; i<9; i++){
        if(i==6) curfrq=frq[6]/2+frq[6]%2;
        else curfrq=frq[i];
        if(maxfrq<curfrq) maxfrq=curfrq;
    }
    printf("%d\n", maxfrq);
    return 0;
}
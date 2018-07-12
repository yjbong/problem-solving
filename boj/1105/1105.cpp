#include <stdio.h>
int dgt1[15];
int dgt2[15];
int main(void){

    int i,l,r,sol;
    for(i=0; i<15; i++){
        dgt1[i]=0;
        dgt2[i]=0;
    }
    scanf("%d %d", &l, &r);
    i=0;
    while(l>0){
        dgt1[i]=l%10;
        l/=10;
        i++;
    }
    i=0;
    while(r>0){
        dgt2[i]=r%10;
        r/=10;
        i++;
    }
    sol=0;
    for(i=15; i>=0; i--){
        if(dgt1[i]!=dgt2[i]) break;
        else if(dgt1[i]==8) sol++;
    }
    printf("%d\n", sol);
    return 0;
}
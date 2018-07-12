#include <stdio.h>
int main(void){

    int i,n,l,d,k,sol;
    scanf("%d %d %d",&n,&l,&d);

    k=(n*l+5*(n-1))/d;
    if((n*l+5*(n-1))%d>0) k++;
    sol=k*d;

    for(i=1; i*d<sol; i++){
        if((i*d)%(l+5)>=l && (i*d)%(l+5)<=l+4){
            sol=i*d;
            break;
        }
    }
    printf("%d\n",sol);
}
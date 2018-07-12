#include <stdio.h>
#define SWAP(a,b,tmp){tmp=a;a=b;b=tmp;}
int main(void){

    int i,j,k,l,n[9],sum,sol[7],tmp;
    for(i=0; i<9; i++) scanf("%d",&n[i]);
    for(i=0; i<9; i++){
        for(j=i+1; j<9; j++){
            sum=0;
            for(k=0; k<9; k++)
                if(k!=i && k!=j) sum+=n[k];
            if(sum==100){
                for(k=0,l=0; k<9; k++){
                    if(k!=i && k!=j){
                        sol[l]=n[k];
                        l++;
                    }
                }
            }
        }
    }
    for(i=0; i<7; i++){
        for(j=i+1; j<7; j++){
            if(sol[i]>sol[j]) SWAP(sol[i],sol[j],tmp);
        }
    }
    for(i=0; i<7; i++) printf("%d\n",sol[i]);
    return 0;
}
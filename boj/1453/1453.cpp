#include <stdio.h>
int occ[101];
int main(void){

    int i,n,rejs,q;
    for(i=1; i<=100; i++) occ[i]=0;
    scanf("%d", &n);
    rejs=0;
    while(n--){
        scanf("%d", &q);
        if(occ[q]==1) rejs++;
        else occ[q]=1;
    }
    printf("%d\n", rejs);
    return 0;
}
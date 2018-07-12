#include <stdio.h>
int d[1000001];
int main(void){

    int i,n,m,in,maxp=0;
    int sol,solp,curp;
    scanf("%d %d",&n,&m);
    for(i=0; i<m; i++){
        scanf("%d",&in);
        if(maxp<in) maxp=in;
        d[in]++;
    }
    for(i=maxp-1; i>=0; i--) d[i]+=d[i+1];
    sol=maxp;
    if(d[maxp]>n) solp=maxp*n;
    else solp=maxp*d[maxp];

    for(i=maxp-1; i>=0; i--){
        if(d[i]>n) curp=i*n;
        else curp=i*d[i];
        if(solp<curp) sol=i, solp=curp;
    }
    printf("%d %d\n",sol,solp);
    return 0;
}
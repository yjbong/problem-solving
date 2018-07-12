#include <stdio.h>
#define SWAP(a,b,t){t=a;a=b;b=t;}
int a[50001];
int c[50001];
int p[50001];
int main(void){

    int i,n,t,curp;
    scanf("%d",&n);
    for(i=0; i<n; i++){
        scanf("%d",&a[i]);
        p[a[i]]=i;
    }
    for(i=0; i<n; i++){
        if(a[i]>1){
            curp=p[a[i]-1];
            if(i<curp && c[i]==0 && c[curp]==0){
                SWAP(a[i],a[curp],t);
                c[i]=c[curp]=1;
            }
        }
    }
    for(i=0; i<n; i++) printf("%d\n",a[i]);
    return 0;
}
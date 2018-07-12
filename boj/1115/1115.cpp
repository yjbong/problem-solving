#include <stdio.h>
#define SWAP(a,b,tmp) {tmp=a;a=b;b=tmp;}
int q[50];
int c[50];

int main(void){

    int i,n,cycles,cs,cur;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d", &q[i]);
    for(i=0; i<n; i++) c[i]=0;
    cycles=0;
    cs=0;
    cur=0;
    while(1){
        while(c[cur]==0){
            c[cur]=1;
            cs++;
            cur=q[cur];
        }
        cycles++;
        if(cs>=n) break;
        for(i=0; i<n; i++){
            if(c[i]==0){
                cur=i;
                break;
            }
        }
    }

    if(cycles==1) cycles=0;
    printf("%d\n", cycles);
    return 0;
}
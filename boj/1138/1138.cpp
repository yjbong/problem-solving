#include <stdio.h>
int pos[10];
int input[10];
int main(void){

    int n,i,j;
    int vacs;
    scanf("%d", &n);

    for(i=0; i<10; i++) pos[i]=0;
    for(i=0; i<n; i++) scanf("%d", &input[i]);

    for(i=0; i<n; i++){
        vacs=0;
        for(j=0; j<n; j++){
            if(pos[j]==0) vacs++;
            if(vacs>=input[i]+1) break;
        }
        pos[j]=i+1;
    }

    for(i=0; i<n; i++){
        printf("%d", pos[i]);
        if(i==n-1) printf("\n");
        else printf(" ");
    }

    return 0;
}
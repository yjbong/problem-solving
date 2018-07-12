#include <stdio.h>
int c[2000001];
int d[111];
int main(void){

    int n,e,i,j;
    scanf("%d %d",&n,&e);
    for(i=0; i<n; i++) scanf("%d",&d[i]);

    for(i=0; i<n; i++)
        for(j=d[i]; j<=e; j+=d[i]) c[j]=1;

    int sol=0;
    for(i=0; i<=e; i++) if(c[i]) sol++;
    printf("%d\n",sol);
    return 0;
}
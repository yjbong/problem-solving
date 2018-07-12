#include <stdio.h>
#define INF 100000000
int d[1000001];
int main(void){

    int i,n;
    d[1]=0,d[2]=1,d[3]=1;
    scanf("%d", &n);

    for(i=4; i<=n; i++) d[i]=INF;
    for(i=4; i<=n; i++){
        if(i%3==0 && d[i]>d[i/3]+1) d[i]=d[i/3]+1;
        if(i%2==0 && d[i]>d[i/2]+1) d[i]=d[i/2]+1;
        if(d[i]>d[i-1]+1) d[i]=d[i-1]+1;
    }
    printf("%d\n", d[n]);
    return 0;
}
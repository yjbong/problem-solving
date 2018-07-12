#include <stdio.h>
int d[10001][3];
int w[10001];
int max(int a, int b){
    if(a>b) return a;
    else return b;
}
int main(void){

    int i,n,sol;
    scanf("%d", &n);
    for(i=1; i<=n; i++) scanf("%d", &w[i]);
    d[1][0]=0, d[1][1]=w[1], d[1][2]=w[1];
    d[2][0]=w[1], d[2][1]=w[1], d[2][2]=w[1]+w[2];

    for(i=3; i<=n; i++){
        d[i][0]=max(max(d[i-1][0],d[i-1][1]), d[i-1][2]);
        d[i][1]=d[i-1][0]+w[i];
        d[i][2]=d[i-2][0]+w[i-1]+w[i];
    }
    sol=max(max(d[n][0],d[n][1]),d[n][2]);
    printf("%d\n", sol);
    return 0;
}
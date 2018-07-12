#include <cstdio>
#define M_INF -2000000000
int a[3001];
int d[3001][3001][2];
int max2(int a, int b){

    if(a>b) return a;
    else return b;
}
int main(void){

    int n,b;
    scanf("%d %d",&n,&b);
    for(int i=1; i<=n; i++) scanf("%d",&a[i]);
    d[0][0][0]=0;
    d[0][0][1]=M_INF;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=b; j++){
            if(j==0){
                d[i][j][0]=0;
                d[i][j][1]=M_INF;
            }
            else{
                d[i][j][0]=max2(d[i-1][j][0],d[i-1][j][1]);
                d[i][j][1]=max2(d[i-1][j-1][0],d[i-1][j-1][1]+a[i]);
            }
        }
    }
    int sol=0;
    for(int i=0; i<=n; i++)
        for(int k=0; k<=1; k++)
            if(sol<d[i][b][k]) sol=d[i][b][k];

    printf("%d\n",sol);
    return 0;
}
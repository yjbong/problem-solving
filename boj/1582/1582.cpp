#include <cstdio>
#define W 0
#define B 1
int d[2][3100][2];
int a[10001];
char l[101];
int min2(int a, int b){
    if(a<b) return a;
    else return b;
}
int main(void){

    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0; i<n; i++){
        scanf("%s",l);
        for(int j=0; j<m; j++){
            if(l[j]=='W') a[i*m+j+1]=W;
            else a[i*m+j+1]=B;
        }
    }

    for(int j=0; j<=k; j++) d[0][j][W]=d[0][j][B]=n*m;

    int cur,sol=n*m;
    for(int i=1; i<=n*m; i++){

        if(i==1) d[1-i%2][0][W]=d[1-i%2][0][B]=0;
        else d[1-i%2][0][W]=d[1-i%2][0][B]=n*m;

        for(int j=1; j<=k; j++){
            if(i%m!=1){
                d[i%2][j][W]=min2(d[1-i%2][j][W],d[1-i%2][j-1][B])+(a[i]!=W);
                d[i%2][j][B]=min2(d[1-i%2][j-1][W],d[1-i%2][j][B])+(a[i]!=B);
            }
            else{
                d[i%2][j][W]=min2(d[1-i%2][j-1][W],d[1-i%2][j-1][B])+(a[i]!=W);
                d[i%2][j][B]=min2(d[1-i%2][j-1][W],d[1-i%2][j-1][B])+(a[i]!=B);
            }
            cur=min2(d[i%2][j][W],d[i%2][j][B])+(n*m-i);
            if(sol>cur) sol=cur;
        }
    }
    printf("%d\n",sol);
    return 0;
}
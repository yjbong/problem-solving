#include <stdio.h>
#define R 0
#define G 1
#define B 2
int d[1000][3];
int a[1000][3];

int min(int a, int b){

    if(a<b) return a;
    else return b;
}

int main(void){

    int i,j,n,sol;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        for(j=R; j<=B; j++){
            scanf("%d", &a[i][j]);
        }
    }

    d[0][R]=a[0][R], d[0][G]=a[0][G], d[0][B]=a[0][B];
    for(i=1; i<n; i++){
        for(j=R; j<=B; j++){
            if(j==R) d[i][j]=min(d[i-1][G]+a[i][R], d[i-1][B]+a[i][R]);
            else if(j==G) d[i][j]=min(d[i-1][R]+a[i][G], d[i-1][B]+a[i][G]);
            else if(j==B) d[i][j]=min(d[i-1][R]+a[i][B], d[i-1][G]+a[i][B]);
        }
    }

    sol=d[n-1][R];
    if(sol>d[n-1][G]) sol=d[n-1][G];
    if(sol>d[n-1][B]) sol=d[n-1][B];

    printf("%d\n", sol);

    return 0;
}
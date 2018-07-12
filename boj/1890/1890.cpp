#include <cstdio>
int a[111][111];
long long d[111][111];

int main(void){
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) scanf("%d",&a[i][j]);

    d[0][0]=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(d[i][j] && a[i][j]){
                d[i+a[i][j]][j]+=d[i][j];
                d[i][j+a[i][j]]+=d[i][j];
            }
        }
    }
    printf("%lld\n",d[n-1][n-1]);
    return 0;
}
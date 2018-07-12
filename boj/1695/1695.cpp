#include <cstdio>
int a[5001];
int b[5001];
int d[5001][5001];
int max(int x,int y){
        if(x>y) return x;
        else return y;
}
int main(void){
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++){
                scanf("%d",&a[i]);
                b[n+1-i]=a[i];
        }
        for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                        if(a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
                        else d[i][j]=max(d[i-1][j],d[i][j-1]);
                }
        }
        printf("%d\n",n-d[n][n]);
        return 0;
}
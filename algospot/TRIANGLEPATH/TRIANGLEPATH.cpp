#include <cstdio>
int c,n;
int a[111][111];
int d[111][111];
int max2(int a, int b){
    return a>b?a:b;
}
int main(void){
    scanf("%d",&c);
    while(c--){
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            for(int j=0; j<=i; j++)
                scanf("%d",&a[i][j]);

        d[0][0]=a[0][0];
        for(int i=1; i<n; i++){
            for(int j=0; j<=i; j++){
                if(j>0) d[i][j]=max2(d[i-1][j-1],d[i-1][j]);
                else d[i][j]=d[i-1][j];
                d[i][j]+=a[i][j];
            }
        }

        int ans=0;
        for(int i=0; i<n; i++)
            ans=max2(ans,d[n-1][i]);
        printf("%d\n",ans);
    }
    return 0;
}
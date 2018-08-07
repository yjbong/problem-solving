#include <cstdio>
#include <algorithm>
#define INF 1000000000
int c,n,s;
int a[111];
int sum[111];
int d[11][111];

int min2(int a, int b){
        return (a<b ? a : b);
}
int diff_square(int start, int end){
        int avg=(sum[end]-sum[start-1])/(end-start+1);
        int ret1=0;
        for(int i=start; i<=end; i++)
                ret1 += (a[i]-avg)*(a[i]-avg);

        int ret2=0;
        for(int i=start; i<=end; i++)
                ret2 += (a[i]-(avg+1))*(a[i]-(avg+1));

        return min2(ret1,ret2);
}

int main(void){

        scanf("%d",&c);
        while(c--){
                scanf("%d %d",&n,&s);
                for(int i=1; i<=n; i++) scanf("%d",&a[i]);
                std::sort(a+1,a+n+1);
                for(int i=0; i<=s; i++)
                        for(int j=0; j<=n; j++) d[i][j]=INF;

                sum[0]=0; sum[1]=a[1];
                for(int i=2; i<=n; i++) sum[i]=sum[i-1]+a[i];

                for(int i=1; i<=n; i++) d[1][i]=diff_square(1,i);
                for(int i=2; i<=s; i++){
                        for(int j=i; j<=n; j++){
                                for(int k=1; k<=j-1; k++){
                                        d[i][j]=min2(d[i][j],d[i-1][k]+diff_square(k+1,j));
                                }
                        }
                }

                int ans=INF;
                for(int i=0; i<=s; i++)
                        ans=min2(ans,d[i][n]);
                printf("%d\n",ans);
        }
        return 0;
}
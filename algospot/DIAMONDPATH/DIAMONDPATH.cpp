#include <cstdio>
#include <cstdlib>
int t,n;
int a[100*2-1][100];
int d[100*2-1][100];
int max2(int a, int b){
        return a>b?a:b;
}
int main(void){
        scanf("%d",&t);
        while(t--){
                scanf("%d",&n);
                for(int i=0; i<n*2-1; i++)
                        for(int j=0; j<n-abs(n-1-i); j++) scanf("%d",&a[i][j]);

                d[0][0]=a[0][0];
                for(int i=1; i<n*2-1; i++){
                        for(int j=0; j<n-abs(n-1-i); j++){
                                d[i][j]=0;
                                if(i<n){
                                        d[i][j]=max2(d[i][j],d[i-1][j-1]);
                                        d[i][j]=max2(d[i][j],d[i-1][j]);
                                }
                                else{
                                        d[i][j]=max2(d[i][j],d[i-1][j]);
                                        d[i][j]=max2(d[i][j],d[i-1][j+1]);
                                }
                                d[i][j]+=a[i][j];
                        }
                }
                printf("%d\n",d[n*2-2][0]);
        }
        return 0;
}
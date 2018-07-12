#include <cstdio>
int d[10001];
int a[100];
int main(void){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0; i<n; i++) scanf("%d",&a[i]);
    d[0]=1;
    for(int i=0; i<n; i++)
        for(int j=1; j<=k; j++)
            if(j-a[i]>=0) d[j]+=d[j-a[i]];
    printf("%d\n",d[k]);
    return 0;
}
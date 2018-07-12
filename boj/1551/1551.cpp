#include <stdio.h>
int a[20];
int main(void){
    int i,j,n,k;
    scanf("%d %d",&n,&k);
    for(i=0; i<n; i++) scanf("%d,",&a[i]);
    for(i=1; i<=k; i++)
        for(j=0; j<n-i; j++) a[j]=a[j+1]-a[j];
    for(i=0; i<n-k; i++){
        printf("%d",a[i]);
        if(i==n-k-1) printf("\n");
        else printf(",");
    }
    return 0;
}
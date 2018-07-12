#include <cstdio>
int a[100];
int main(void){
    int n,s;
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d",&a[i]);
    if(a[1]-a[0]==a[2]-a[1]) s=a[n-1]+(a[1]-a[0]);
    else if(a[1]/a[0]==a[2]/a[1]) s=a[n-1]*(a[1]/a[0]);
    printf("%d\n",s);
    return 0;
}
#include <cstdio>
#include <algorithm>
using namespace std;
int a[1111111];
int main(void){

    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d",&a[i]);
    sort(a,a+n);
    int sol=-1;
    for(int i=n-1; i>=2; i--){
        if(a[i-2]+a[i-1]>a[i]){
            sol=a[i]+a[i-1]+a[i-2];
            break;
        }
    }
    printf("%d\n",sol);
    return 0;
}
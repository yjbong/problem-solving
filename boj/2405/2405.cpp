#include <cstdio>
#include <algorithm>
using namespace std;
int a[100000];
int main(void){

    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d",&a[i]);
    sort(a,a+n);

    int sol=0;
    for(int i=0; i<n-2; i++){

        int c;
        c=a[i]+a[i+1]+a[n-1]-3*a[i+1];
        if(c<0) c=-c;
        if(sol<c) sol=c;

        c=a[i]+a[n-2]+a[n-1]-3*a[n-2];
        if(c<0) c=-c;
        if(sol<c) sol=c;
    }

    for(int i=n-1; i>=2; i--){

        int c;

        c=a[0]+a[1]+a[i]-3*a[1];
        if(c<0) c=-c;
        if(sol<c) sol=c;

        c=a[0]+a[i-1]+a[i]-3*a[i-1];
        if(c<0) c=-c;
        if(sol<c) sol=c;
    }
    printf("%d\n",sol);
    return 0;
}
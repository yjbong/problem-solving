#include <cstdio>
#include <algorithm>
using namespace std;
long long x[11111];
int main(void){

    long long n;
    scanf("%lld",&n);
    for(long long i=0; i<n; i++) scanf("%lld",&x[i]);
    sort(x,x+n);
    long long l,r;
    l=r=0;
    for(long long i=0; i<n; i++) r+=x[i]-x[0];

    long long sol=l+r;
    for(long long i=1; i<n; i++){
        l+=(x[i]-x[i-1])*i;
        r-=(x[i]-x[i-1])*(n-i);
        sol+=l+r;
    }
    printf("%lld\n",sol);
    return 0;
}
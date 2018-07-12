#include <stdio.h>
int main(void){

    long long i,n,c[20];
    long long y,m;
    scanf("%lld", &n);
    for(i=0; i<n; i++) scanf("%lld", &c[i]);

    y=m=0;
    for(i=0; i<n; i++){
        if(c[i]>0) y+=(c[i]/30+1)*10;
        if(c[i]>0) m+=(c[i]/60+1)*15;
    }

    if(y==m) printf("Y M %lld\n", y);
    else if(y<m) printf("Y %lld\n", y);
    else printf("M %lld\n", m);
    return 0;
}
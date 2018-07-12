#include <stdio.h>
#include <stdlib.h>
#define INF 2147483647
long long a[111111];
long long diff[111111];
long long diffs;

int cmp(const void *a, const void *b){

    if(*((long long*)a)>*((long long*)b)) return 1;
    else return 0;
}

int main(void){

    long long i, n, m;
    long long sol;
    long long s, e, sum;
    scanf("%lld %lld", &n, &m);
    for(i=0; i<n; i++) scanf("%lld", &a[i]);
    qsort(a, n, sizeof(long long), cmp);

    diffs=0;
    for(i=1; i<n; i++){
        if(a[i]-a[i-1]>0){
            diff[diffs]=a[i]-a[i-1];
            diffs++;
        }
    }

    sol=INF;
    sum=diff[0];
    s=e=0;

    while(1){
        if(sum<m){
            e++;
            if(e>=diffs) break;
            sum+=diff[e];
        }
        else if(sum==m){
            sol=m;
            break;
        }

        else if(sum>m){
            if(sol>sum) sol=sum;
            sum-=diff[s];
            s++;
        }
    }
    if(sol!=INF) printf("%lld\n", sol);
    return 0;
}
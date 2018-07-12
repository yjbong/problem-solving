#include <cstdio>
long long a[100000];
int main(void){

    long long n,m;
    scanf("%lld %lld",&n,&m);
    long long sum=0;
    long long max=0;
    for(int i=0; i<n; i++){
        scanf("%lld",&a[i]);
        sum+=a[i];
        if(max<a[i]) max=a[i];
    }

    long long left=max, right=sum;
    long long sol=sum;

    while(left<right){

        long long mid=(left+right)/2;

        long long recs=1;
        long long len=a[0];
        bool ok=true;

        for(int i=1; i<n; i++){

            if(len+a[i]>mid){
                recs++;
                len=a[i];
            }
            else len+=a[i];
        }

        if(recs<=m){
            if(sol>mid) sol=mid;
            right=mid;
        }
        else left=mid+1;
    }
    printf("%lld\n",sol);
    return 0;
}
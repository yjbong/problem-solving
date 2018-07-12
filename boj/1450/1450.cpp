#include <cstdio>
#include <algorithm>
using namespace std;
long long a[20];
long long b[20];
long long s1[1<<15];
long long s2[1<<15];

int binsrch(long long a[], int asize, long long key){

    int l,m,r;
    int ret=-1;

    l=0, r=asize-1;
    while(l<=r){
        m=(l+r)/2;
        if(a[m]<=key){
            if(ret<m) ret=m;
            l=m+1;
        }
        else r=m-1;
    }
    return ret;
}

int main(void){

    long long n,c;
    scanf("%lld %lld",&n,&c);
    int as,bs;
    as=bs=0;
    int i;
    for(i=0; i<n/2; i++,as++) scanf("%lld",&a[as]);
    for(; i<n; i++,bs++) scanf("%lld",&b[bs]);

    int s1s,s2s;
    s1s=1<<as;
    s2s=1<<bs;

    for(int i=0; i<s1s; i++){
        int t=i,cur=0;
        while(t>0){
            if(t%2) s1[i]+=a[cur];
            t/=2;
            cur++;
        }
    }

    for(int i=0; i<s2s; i++){
        int t=i,cur=0;
        while(t>0){
            if(t%2) s2[i]+=b[cur];
            t/=2;
            cur++;
        }
    }

    sort(s1,s1+s1s);
    sort(s2,s2+s2s);

    long long sol=0;
    for(int i=0; i<s1s; i++){
        long long key=c-s1[i];
        int idx=binsrch(s2,s2s,key);
        sol+=(idx+1);
    }
    printf("%lld\n",sol);
    return 0;
}
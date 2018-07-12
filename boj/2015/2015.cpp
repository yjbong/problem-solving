#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

int a[200000];
int d[200000];
int c[200000];

pair <int,int> f[200000];
int fs;

int binsearch(int l, int r, int key){

    int m;
    //l=0; r=fs-1;
    while(l<=r){
        m=(l+r)/2;
        if(f[m].first<key) l=m+1;
        else if(f[m].first>key) r=m-1;
        else return m;
    }
    return -1;
}
int main(void){

    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0; i<n; i++) scanf("%d",&a[i]);

    d[0]=a[0];
    for(int i=1; i<n; i++) d[i]=d[i-1]+a[i];
    for(int i=0; i<n; i++) c[i]=d[i];
    sort(c,c+n);

    fs=0;
    for(int i=0; i<n; i++){
        int idx=binsearch(0,fs-1,c[i]);
        if(idx<0){
            f[fs].first = c[i];
            f[fs].second = 1;
            fs++;
        }
        else f[idx].second++;
    }

    long long sol=0;
    for(int i=0; i<n; i++){

        int idx;
        if(i>0){
            idx=binsearch(0,fs-1,d[i-1]);
            f[idx].second--;
            idx=binsearch(0,fs-1,k+d[i-1]);
            sol += f[idx].second;
        }
        else{
            idx=binsearch(0,fs-1,k);
            sol += f[idx].second;
        }
    }
    printf("%lld\n",sol);
    return 0;
}
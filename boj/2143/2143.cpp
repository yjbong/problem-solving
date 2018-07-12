#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

ll a[1000];
ll b[1000];
ll t,n,m;
ll asum[1000*1001/2];
ll bsum[1000*1001/2];
ll tmp[1000];
ll asums,bsums,tmps;

vector <ii> bf;

ll bsearch(ll key){

    ll sol=0;
    int l,m,r;
    l=0, r=bf.size()-1;
    while(l<=r){
        m=(l+r)/2;
        if(bf[m].first>key) r=m-1;
        else if(bf[m].first<key) l=m+1;
        else return bf[m].second;
    }
    return 0;
}

int main(void){

    scanf("%lld",&t);
    scanf("%lld",&n);
    for(int i=0; i<n; i++) scanf("%lld",&a[i]);
    scanf("%lld",&m);
    for(int i=0; i<m; i++) scanf("%lld",&b[i]);

    for(int i=0; i<n; i++){
        tmps=0;
        tmp[tmps++]=a[i];
        for(int j=i+1; j<n; j++) tmp[tmps++]=tmp[tmps-1]+a[j];
        for(int j=0; j<tmps; j++) asum[asums++]=tmp[j];
    }

    for(int i=0; i<m; i++){
        tmps=0;
        tmp[tmps++]=b[i];
        for(int j=i+1; j<m; j++) tmp[tmps++]=tmp[tmps-1]+b[j];
        for(int j=0; j<tmps; j++) bsum[bsums++]=tmp[j];
    }

    sort(bsum,bsum+bsums);

    bf.push_back(ii(bsum[0],1));
    for(int i=1; i<bsums; i++){
        ii last=bf[bf.size()-1];
        if(bsum[i]==last.first) bf[bf.size()-1].second++;
        else bf.push_back(ii(bsum[i],1));
    }

    ll sol=0;
    for(int i=0; i<asums; i++) sol+=bsearch(t-asum[i]);
    printf("%lld\n",sol);
    return 0;
}
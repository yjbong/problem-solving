#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
ii a[100000];

bool cmp1(ii a,ii b){

    if(a.first>b.first) return true;
    else if(a.first==b.first){
        if(a.second>b.second) return true;
        else return false;
    }
    else return false;
}

bool cmp2(ii a,ii b){

    if(a.second>b.second) return true;
    else if(a.second==b.second){
        if(a.first>b.first) return true;
        else return false;
    }
    else return false;
}

int main(void){

    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        long long t1,t2;
        scanf("%lld %lld",&t1,&t2);
        a[i].first=t1, a[i].second=t2;
    }

    ll sol=0;

    sort(a,a+n,cmp1);
    for(int i=0; i<n; i+=2) sol+=a[i].second-a[i+1].second;

    sort(a,a+n,cmp2);
    for(int i=0; i<n; i+=2) sol+=a[i].first-a[i+1].first;

    printf("%lld\n",sol);
    return 0;
}
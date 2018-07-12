#include <cstdio>
#include <algorithm>
#include <vector>
#define _x first
#define _y second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii; // (x,y)
ii p[100000];

vector <ii> s;

int ccw(ii a, ii b, ii c){

    ll t = a._x*b._y + b._x*c._y + c._x*a._y - (b._x*a._y + c._x*b._y + a._x*c._y);
    if(t<0) return -1;
    else if(t>0) return 1;
    else return 0;
}

ll dst(ii a, ii b){
    return (a._x-b._x)*(a._x-b._x) + (a._y-b._y)*(a._y-b._y);
}
bool cmp(const ii &a, const ii &b){

    int t=ccw(p[0],a,b);
    if(t>0) return true;
    else if(t==0){
        if(dst(p[0],a)<dst(p[0],b)) return true;
        else return false;
    }
    else return false;
}

int main(void){

    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%lld %lld",&p[i]._x,&p[i]._y);

    swap(p[0],*min_element (p, p+n));
    sort(p+1,p+n,cmp);

    for(int i=0; i<n; i++){
        while(s.size()>=2 && ccw(s[s.size()-2],s[s.size()-1],p[i]) <= 0) s.pop_back();
        s.push_back(p[i]);
    }
    printf("%d\n",s.size());
    return 0;
}
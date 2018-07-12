#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

ii p[10000];
int n;

ll ccw(ii a, ii b, ii c){

    ll t = a.first*b.second + b.first*c.second + c.first*a.second - (b.first*a.second + c.first*b.second + a.first*c.second);
    return t;
}

int main(void){

    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%lld %lld",&p[i].first,&p[i].second);

    double sol=0.0;

    for(int i=0; i<n; i++) // q(0,0)
        sol+=ccw(ii(0,0),p[i],p[(i+1)%n]);

    printf("%.1lf\n",0.5*fabs(sol));
    return 0;
}
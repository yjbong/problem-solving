#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#define INF 1000000000000000ll

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
priority_queue <ii> pq;

vector <ii> a[1001];

ll d[1001];
ll p1,p2;

ll n,e;

void dijkstra(ll s){

    for(ll i=1; i<=n; i++) d[i]=INF;
    d[s]=0;
    pq.push(make_pair(0,s));

    while(!pq.empty()){
        ii f=pq.top();
        pq.pop();
        ll fv=f.second;
        for(ll i=0; i<a[fv].size(); i++){
            ll cv=a[fv][i].first;
            ll cc=a[fv][i].second;
            if(d[cv]>d[fv]+cc){
                d[cv]=d[fv]+cc;
                pq.push(make_pair(-d[cv],cv));
            }
        }
    }
}

int main(void){

    scanf("%lld %lld",&n,&e);
    for(ll i=0; i<e; i++){
        ll from,to,cost;
        scanf("%lld %lld %lld",&from,&to,&cost);
        a[from].push_back(make_pair(to,cost));
        a[to].push_back(make_pair(from,cost));
    }
    scanf("%lld %lld",&p1,&p2);

    ll sol1=0;
    dijkstra(1);
    sol1+=d[p1];
    dijkstra(p1);
    sol1+=d[p2];
    dijkstra(p2);
    sol1+=d[n];

    ll sol2=0;
    dijkstra(1);
    sol2+=d[p2];
    dijkstra(p2);
    sol2+=d[p1];
    dijkstra(p1);
    sol2+=d[n];

    ll sol;
    if(sol1<sol2) sol=sol1;
    else sol=sol2;

    if(sol<INF) printf("%lld\n",sol);
    else printf("-1\n");

    return 0;
}
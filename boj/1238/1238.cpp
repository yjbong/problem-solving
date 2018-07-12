#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#define INF 1000000000
using namespace std;
typedef pair<int,int> ii;
priority_queue <ii> pq;
vector <ii> a[1001];

int d[1001];
int sol[1001];

int n,m,x;

void dijkstra(int s){

    for(int i=1; i<=n; i++) d[i]=INF;
    d[s]=0;
    pq.push(make_pair(0,s));

    while(!pq.empty()){
        ii f=pq.top();
        pq.pop();
        int fv=f.second;
        for(int i=0; i<a[fv].size(); i++){
            int cv=a[fv][i].first;
            int cc=a[fv][i].second;
            if(d[cv]>d[fv]+cc){
                d[cv]=d[fv]+cc;
                pq.push(make_pair(-d[cv],cv));
            }
        }
    }
}

int main(void){

    scanf("%d %d %d",&n,&m,&x);
    for(int i=0; i<m; i++){
        int from,to,cost;
        scanf("%d %d %d",&from,&to,&cost);
        a[from].push_back(make_pair(to,cost));
    }

    for(int i=1; i<=n; i++){
        dijkstra(i);
        sol[i]=d[x];
    }

    dijkstra(x);
    for(int i=1; i<=n; i++) sol[i]+=d[i];

    int max=0;
    for(int i=1; i<=n; i++) if(max<sol[i]) max=sol[i];
    printf("%d\n",max);

    return 0;
}
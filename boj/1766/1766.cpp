#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int deg[33333];
vector<int> adj[33333];
int main(void){

    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1; i<=n; i++){
        adj[i].clear();
        deg[i]=0;
    }

    for(int i=0; i<m; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        deg[b]++;
        adj[a].push_back(b);
    }

    priority_queue <int> pq;
    for(int i=1; i<=n; i++) if(deg[i]==0) pq.push(-i);

    while(!pq.empty()){
        int t=-pq.top();
        pq.pop();
        printf("%d ",t);
        for(int i=0; i<adj[t].size(); i++){
            int c=adj[t][i];
            deg[c]--;
            if(deg[c]==0) pq.push(-c);
        }
    }
    printf("\n");
    return 0;
}
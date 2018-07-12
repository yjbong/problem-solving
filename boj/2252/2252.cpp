#include <cstdio>
#include <queue>
using namespace std;

int deg[32001];
vector<int> adj[32001];
int main(void){

    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0; i<m; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        if(a!=b){
            adj[a].push_back(b);
            deg[b]++;
        }
    }
    priority_queue <int> pq;
    for(int i=1; i<=n; i++)
        if(!deg[i]) pq.push(-i);

    bool first=true;
    while(!pq.empty()){
        int t=-pq.top();
        pq.pop();
        if(first) first=false;
        else printf(" ");
        printf("%d",t);
        for(int i=0; i<adj[t].size(); i++){
            int c=adj[t][i];
            deg[c]--;
            if(!deg[c]) pq.push(-c);
        }
    }
    printf("\n");
    return 0;
}
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int bt[1111];
int ans[1111];
int deg[1111];
vector <int> adj[1111];
queue <int> q;
int main(void){

    int t;
    scanf("%d",&t);
    while(t--){
        int w,n,k;
        scanf("%d %d",&n,&k);
        for(int i=1; i<=n; i++){
            adj[i].clear();
            deg[i]=0;
        }

        for(int i=1; i<=n; i++){
            scanf("%d",&bt[i]);
            ans[i]=bt[i];
        }
        for(int i=0; i<k; i++){
            int t1,t2;
            scanf("%d %d",&t1,&t2);
            adj[t1].push_back(t2);
            deg[t2]++;
        }
        scanf("%d",&w);

        for(int i=1; i<=n; i++) if(deg[i]==0) q.push(i);

        while(!q.empty()){
            int f=q.front();
            q.pop();
            for(int i=0; i<adj[f].size(); i++){
                int nxt=adj[f][i];
                ans[nxt]=max(ans[nxt],ans[f]+bt[nxt]);
                deg[nxt]--;
                if(deg[nxt]==0){
                    q.push(nxt);
                }
            }
        }

        printf("%d\n",ans[w]);
    }

    return 0;
}
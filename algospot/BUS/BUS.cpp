#include <cstdio>
#include <vector>
#include <queue>
#define INF 1000000000
#define MAX_N 200
#define MAX_V 2+MAX_N*2

using namespace std;
int cases; // # of test cases
int n; // # of persons
int a[MAX_N]; // a[i] = i-th person's satisfaction value of Tayo bus
int b[MAX_N]; // b[i] = i-th person's satisfaction value of Tobot bus
int h[MAX_N][MAX_N]; // h[i][j] = if i and j-th person take different bus, decreasing satisfaction value by it

int V; // # of vertices in the network
int capacity[MAX_V][MAX_V];
int flow[MAX_V][MAX_V];

int min2(int a, int b){
        return a<b?a:b;
}
int get_maxflow(int source, int sink){
        for(int i=0; i<V; i++)
                for(int j=0; j<V; j++)
                        flow[i][j]=0;

        int maxflow=0;
        while(1){
                vector <int> pre(V,-1);
                queue <int> q;

                // find a augmenting path
                q.push(source);
                pre[source]=source;
                while(!q.empty()){
                        int from=q.front(); q.pop();
                        for(int to=0; to<V; to++){
                                if(capacity[from][to]-flow[from][to]>0 && pre[to]<0){
                                        q.push(to); pre[to]=from;
                                }
                        }
                }
                if(pre[sink]<0) break;

                // calc flow amount for current augmenting path
                int amount=INF;
                for(int i=sink; i!=source; i=pre[i])
                        amount=min2(amount,capacity[pre[i]][i]-flow[pre[i]][i]);

                // add flow to current augmneting path
                for(int i=sink; i!=source; i=pre[i]){
                        flow[pre[i]][i]+=amount;
                        flow[i][pre[i]]-=amount;
                }

                // update return value
                maxflow+=amount;
        }

        return maxflow;
}

void build_network(void){

        for(int i=0; i<V; i++)
                for(int j=0; j<V; j++)
                        capacity[i][j]=0;

        // vertex 0 : source
        // vertex 1 : sink
        // vertex 2 ~ 2+n-1 : for each a[i]
        // vertex 2+n ~ 2+2*n-1 : for each b[i]

        // from source to each a[i]
        for(int i=0; i<n; i++)
                capacity[0][2+i]=a[i];

        // from each b[i] to sink
        for(int i=0; i<n; i++)
                capacity[2+n+i][1]=b[i];

        // from a[i] to b[i]
        for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                        if(i==j) capacity[2+i][2+n+j]=INF; // to prevent i-th person to choose both a[i] and b[i]
                        else capacity[2+i][2+n+j]=h[i][j]; // if i-th person and j-th person choose diff bus
                }
        }
}

int main(void){
        scanf("%d",&cases);
        while(cases--){

                // get input
                scanf("%d",&n);
                for(int i=0; i<n; i++)
                        scanf("%d %d",&a[i],&b[i]);
                for(int i=0; i<n; i++)
                        for(int j=0; j<n; j++)
                                scanf("%d",&h[i][j]);

                // build network
                V=2+2*n;
                build_network();

                // get answer
                int ans=0;
                for(int i=0; i<n; i++) ans+=a[i]+b[i];
                ans-=get_maxflow(0,1);

                // print answer
                printf("%d\n",ans);
        }
        return 0;
}
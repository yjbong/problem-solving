#include <cstdio>
#include <vector>
#include <queue>
#define MAX_V 11111
#define INF 1000000000

using namespace std;
int cases;
int rowSize, colSize;
int toilet[111][111]; // toilet[i][j] is black tile if (i+j) is even, white tile if odd
                      // (chessboard's black & white tile)
int p1, p2;

int brokenTiles; // # of tile marked 0
int V; // # of vertices in network

struct Edge{
        int target, capacity, flow;
        // backward pointer
        Edge* reverse;
        // calculate residual capacity
        int residualCapacity() const { return capacity-flow; }
        // push flow into this edge
        void push(int amt){
                flow += amt;
                reverse->flow -= amt;
        }
};

// network flow (adjacent list)
// vertex 0: source
// vertex 1: sink
// vertex 2~2+rowSize*colSize-1: each tile
vector <Edge*> adj[MAX_V];


int min2(int a, int b){
        return a<b?a:b;
}


// add edge from u to v, with given capacity
// (also add edge from v to u, with zero capacity
void addEdge(int u, int v, int capacity){

        Edge *uv=new Edge(); // uv=forward edge
        Edge *vu=new Edge(); // vu=backward edge

        // set edge uv
        uv->target=v;
        uv->capacity=capacity;
        uv->flow=0;
        uv->reverse=vu;

        // set edge uv
        vu->target=u;
        vu->capacity=0;
        vu->flow=0;
        vu->reverse=uv;

        adj[u].push_back(uv);
        adj[v].push_back(vu);
}

// return maximum flow from source to sink
int getMaxFlow(int source, int sink){
        for(int i=0; i<V; i++)
                for(int j=0; j<adj[i].size(); j++) adj[i][j]->flow=0;

        int totFlow=0;

        while(1){
                vector <int> pre(V,-1);
                queue <int> q;
                q.push(source); pre[source]=source;

                // finding augmenting path
                while(!q.empty()){
                        int from=q.front(); q.pop();
                        for(int i=0; i<adj[from].size(); i++){
                                int to=adj[from][i]->target;
                                if(adj[from][i]->residualCapacity() > 0 && pre[to]==-1){
                                        q.push(to);
                                        pre[to]=from;
                                }
                        }
                }

                if(pre[sink]==-1) break; // no more augmenting path

                // calculate flow amount which will be put into current augmenting path
                int amount=INF;
                for(int i=sink; i!=source; i=pre[i]){
                        for(int j=0; j<adj[pre[i]].size(); j++){
                                if(adj[pre[i]][j]->target == i){
                                        amount=min2(amount,adj[pre[i]][j]->residualCapacity());
                                        break;
                                }
                        }
                }
                // add flow into current augmenting path
                for(int i=sink; i!=source; i=pre[i]){
                        for(int j=0; j<adj[pre[i]].size(); j++){
                                if(adj[pre[i]][j]->target == i){
                                        adj[pre[i]][j]->push(amount);
                                        break;
                                }
                        }
                }

                totFlow+=amount;
        }

        return totFlow;
}

void buildNetwork(){

        // add edges from source to black tiles
        for(int i=0; i<rowSize; i++)
                for(int j=0; j<colSize; j++)
                        if((i+j)%2==0 && toilet[i][j]==0) // valid black tile
                                addEdge(0,2+i*colSize+j,1);

        // add edges from black tiles to white tiles
        for(int i=0; i<rowSize; i++){
                for(int j=0; j<colSize; j++){
                        if((i+j)%2==0){ // black tile
                                if(i>0 && toilet[i-1][j]==0) // up
                                        addEdge(2+i*colSize+j,2+(i-1)*colSize+j,1);
                                if(i<rowSize-1 && toilet[i+1][j]==0) // down
                                        addEdge(2+i*colSize+j,2+(i+1)*colSize+j,1);
                                if(j>0 && toilet[i][j-1]==0) // left
                                        addEdge(2+i*colSize+j,2+i*colSize+j-1,1);
                                if(j<colSize-1 && toilet[i][j+1]==0) // left
                                        addEdge(2+i*colSize+j,2+i*colSize+j+1,1);
                        }
                }
        }

        // add edges from white tiles to sink
        for(int i=0; i<rowSize; i++)
                for(int j=0; j<colSize; j++)
                        if((i+j)%2==1 && toilet[i][j]==0) // valid white tile
                                addEdge(2+i*colSize+j,1,1);
}

int main(void){
        scanf("%d",&cases);
        while(cases--){

                // get input
                scanf("%d %d %d %d",&rowSize,&colSize,&p1,&p2);
                V=2+rowSize*colSize;

                for(int i=0; i<rowSize; i++)
                        for(int j=0; j<colSize; j++)
                                scanf("%1d",&toilet[i][j]);

                // count broken tiles
                brokenTiles=0;
                for(int i=0; i<rowSize; i++)
                        for(int j=0; j<colSize; j++)
                                if(toilet[i][j]==0) brokenTiles++;

                int ans;

                if(p1*2<=p2) // no need to buy 1*2 tiles since using 1*1 is cheaper
                        ans=brokenTiles*p1;
                else{
                        // build network
                        for(int i=0; i<MAX_V; i++) adj[i].clear();
                        buildNetwork();

                        // get # of maximum possible covered area only with 1*2 tiles
                        int maxFlow=getMaxFlow(0,1);

                        ans=maxFlow*p2+(brokenTiles-maxFlow*2)*p1;
                }

                printf("%d\n",ans);
        }

        return 0;
}
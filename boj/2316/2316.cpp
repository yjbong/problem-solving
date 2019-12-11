#include <cstdio>
#include <vector>
#include <queue>
#define INF 1000000000
#define MAX_N 400
#define MAX_P 10000
 
using namespace std;
 
// 유량 네트워크의 간선 정보
struct Edge{
	int target, capacity, flow;
	// 역방향 간선의 포인터
	Edge* reverse;
	// 이 간선의 잔여 용량 계산
	int residualCapacity() const { return capacity-flow; }
	// 이 간선을 따라 유량 amt를 보냄
	void push(int amt){
		flow += amt;
		reverse->flow -= amt;
	}
};
typedef struct Edge Edge;
 
int min2(int a, int b){ return a<b?a:b; }
 
// 유량 네트워크의 인접 리스트
// vertex 0: source (출발지: 1번 도시)
// vertex 1: sink (도착지: 2번 도시)
// 이 문제에서는 정점을 끊어야 하므로, source와 sink를 제외한 각 도시는 in과 out 두 개의 정점으로 분리하여 생각한다
// vertex 2~N-1: 각 정점의 in (즉, i(>2)번 도시의 in은 i-1번 vertex)
// vertex N~2*N-3: 각 정점의 out (즉, i(>2)번 도시의 out은 i+N-3번 vertex)
vector <Edge*> adj[2*MAX_N-2]; // adj[i] = 정점 i와 연결된 간선 리스트
int N; // 도시의 수
int P; // 길의 수
 
// u에서 v로 가는 간선을 추가
void addEdge(int u, int v, int capacity){
 
	Edge *uv=new Edge(); // uv=forward edge
	Edge *vu=new Edge(); // vu=backward edge
 
	// u에서 v로 가는 간선을 초기화
	uv->target=v;
	uv->capacity=capacity;
	uv->flow=0;
	uv->reverse=vu;
 
	// v에서 u로 가는 간선을 초기화 (이 간선의 용량은 0)
	vu->target=u;
	vu->capacity=0;
	vu->flow=0;
	vu->reverse=uv;
 
	adj[u].push_back(uv);
	adj[v].push_back(vu);
}
 
int getMaxFlow(int source, int sink){
	int totFlow=0;
	while(1){
		vector <int> pre(2*N-2,-1); // augmenting path를 저장
		queue <int> q;
		q.push(source); pre[source]=source; // q, pre의 초기화
 
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
 
int getIn(int city){
    return city-1;
}
int getOut(int city){
    if(city<=2) return city-1;
    else return city+N-3;
}
 
 
int main() {
 
    scanf("%d %d",&N,&P);
    for(int i=3; i<=N; i++){
        // i(>2)번 도시의 in과 out 연결
        int in=getIn(i), out=getOut(i);
        addEdge(in, out, 1);
    }
    for(int i=0; i<P; i++){
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        int in1=getIn(v1), out1=getOut(v1);
        int in2=getIn(v2), out2=getOut(v2);
        // out->in을 서로 연결
        addEdge(out1, in2, INF);
        addEdge(out2, in1, INF);
    }
    printf("%d\n",getMaxFlow(0,1));
 
    return 0;
}
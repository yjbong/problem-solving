#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>

#define MAX_N 100
#define INF 1000000000
using namespace std;

int N; // 사람 수(=노트북 수)
int M; // guess의 수
vector <int> guess[MAX_N]; // guess[i] = i번 학생이 자신의 것이라고 생각하는 노트북의 idx
			   // (학생과 노트북의 idx는 0부터 시작한다고 하자)

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

// 유량 네트워크의 인접 리스트
// vertex 0: source
// vertex 1: sink
// vertex 2~2+N-1: 학생
// vertex 2+N~2+2*N-1: 노트북

vector <Edge*> adj[2+2*MAX_N]; // adj[i] = 정점 i와 연결된 간선 리스트

int min2(int a, int b){
	return a<b?a:b;
}

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

void buildNetwork(){

	// source와 학생을 연결
	for(int i=2; i<2+N; i++) addEdge(0,i,1);

	// sink와 노트북을 연결
	for(int i=2+N; i<2+2*N; i++) addEdge(i,1,1);

	// 학생과 노트북을 연결
	for(int i=0; i<N; i++){ // 각 i번 학생에 대해...
		for(int j=0; j<guess[i].size(); j++){
			int fromVertex=2+i;
			int toVertex=2+N+guess[i][j];
			addEdge(fromVertex,toVertex,1);
		}
	}
}

int getMaxFlow(int source, int sink){
	int totFlow=0;
	while(1){
		vector <int> pre(2+2*N*M,-1); // augmenting path를 저장
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

int main(void){

	scanf("%d %d",&N,&M);
	for(int i=0; i<M; i++){
		int student, notebook;
		scanf("%d %d",&student,&notebook);
		guess[student-1].push_back(notebook-1); // idx를 1씩 빼서 0부터 시작하도록 한다.
	}
	int ans=0;
	buildNetwork();
	ans=getMaxFlow(0,1);	
	printf("%d\n",ans);
	return 0;
}
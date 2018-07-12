#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>

#define MAX_N 100
#define MAX_M 100
#define INF 1000000000

using namespace std;

int N;
int M;
char map[MAX_N][MAX_M+1];

const int dy[4]={-1,1,0,0};
const int dx[4]={0,0,1,-1};

int srcY, srcX; // 시작 위치의 y, x좌표
int snkY, snkX; // 도착 위치의 y, x좌표

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
// vertex 0: source (출발 위치)
// vertex 1: sink (학교 위치)
// 이 문제에서는 정점을 끊어야 하므로, source와 sink를 제외한 각 정점을 in과 out 두 개로 분리하여 생각한다
// vertex 2~2+N*M-1: 각 정점의 in (즉, 칸(i,j)의 in은 2+i*M+j번)
// vertex 2+N*M~2+2*N*M-1: 각 정점의 out (즉, 칸(i,j)의 out은 2+N*M+i*M+j번)

vector <Edge*> adj[2+2*MAX_N*MAX_M]; // adj[i] = 정점 i와 연결된 간선 리스트

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

	// 동일한 정점의 in, out에 대한 연결
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			int inVertex=2+i*M+j;
			int outVertex=2+N*M+i*M+j;
			// 해당 위치에 벽이 이미 있는 경우는 가지 못하는 정점이다
			if(map[i][j]=='#') addEdge(inVertex,outVertex,0);
			else addEdge(inVertex,outVertex,1);
		}
	}

	// 서로 다른 정점 간 연결
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){

			int fromVertex;
			if(i==srcY && j==srcX) fromVertex=0; // source
			else if(i==snkY && j==snkX) fromVertex=1; // sink
			else fromVertex=2+N*M+i*M+j; // out vertex of (i,j)

			for(int k=0; k<4; k++){
				int cy=i+dy[k];
				int cx=j+dx[k];

				if(cy>=0 && cy<N && cx>=0 && cx<M){
					int toVertex;
					if(cy==srcY && cx==srcX) toVertex=0; // source
					else if(cy==snkY && cx==snkX) toVertex=1; // sink
					else toVertex=2+cy*M+cx; // in vertex of (cy,cx)

					addEdge(fromVertex,toVertex,INF);
				}
			}
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
	scanf("%d %d\n",&N,&M);
	for(int i=0; i<N; i++) gets(map[i]);

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(map[i][j]=='K'){ srcY=i; srcX=j; }
			else if(map[i][j]=='H'){ snkY=i; snkX=j; }
		}
	}

	int ans;
	// 시작점과 도착점이 바로 인접해 있는 경우
	if(srcY==snkY && abs(srcX-snkX)<=1) ans=-1;
	else if(srcX==snkX && abs(srcY-snkY)<=1) ans=-1;
	// 이외의 경우 maximum flow 계산
	else{
		buildNetwork();
		ans=getMaxFlow(0,1);
	}
	printf("%d\n",ans);
	return 0;
}
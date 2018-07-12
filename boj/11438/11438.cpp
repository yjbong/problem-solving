#include <cstdio>
#include <vector>
#include <queue>
#define MAX_V 100000 // 최대 정점 개수
#define INF 1000000000
using namespace std;
int N; // 노드의 개수
int M; // 정점 쌍(쿼리)의 개수

int min2(int a, int b){ return a<b?a:b; }

vector <int> adj[MAX_V+1]; // adj[i] = i번 정점과 직접 연결된 정점 목록

int lv[MAX_V+1]; // lv[i] = i번 정점의 레벨 (루트의 레벨은 1)
queue <int> q;
int p[MAX_V+1]; // p[i] = i번 정점의 부모 (루트의 부모는 0)

bool visited[MAX_V+1];
int org2dfs[MAX_V+1]; // org2dfs[i] = j 이면, 원래 i번이었던 정점이 dfs 방문 순서로는 j번째인 것을 의미
int dfs2org[MAX_V+1]; // dfs2org[i] = j 이면, dfs 방문 순서로는 i번째인 정점이 원래는 j번 정점인 것을 의미
int curDfsIdx;
void makeIdxMap(int idx){ // 원래 idx번째인 정점을 루트로 하는 트리의 org2dfs, dfs2org 값 결정
	org2dfs[idx]=curDfsIdx;
	dfs2org[curDfsIdx++]=idx;
	visited[idx]=true;
	for(int i=0; i<adj[idx].size(); i++){
		int curv=adj[idx][i];
		if(visited[curv]==false) makeIdxMap(curv);
	}
}

vector <int> trip; // 루트 정점에서부터 dfs 탐색했을 때, 방문하는 정점의 순서(dfs 방문 순서에 따른 idx로 표현)
int firstPosInTrip[MAX_V+1]; // firstPosInTrip[i] = 원래 i번째인 정점이 trip 목록에서 처음 등장하는 위치

void makeTrip(int idx){ // 원래 idx번째인 정점을 루트로 하는 트리에 대해 trip정보를 구함

	if(firstPosInTrip[idx]<0) firstPosInTrip[idx]=trip.size();

	trip.push_back(org2dfs[idx]); // trip에는 dfs 탐색했을 때의 idx가 들어감
	visited[idx]=true;
	for(int i=0; i<adj[idx].size(); i++){
		int curv=adj[idx][i];
		if(visited[curv]==false){
			makeTrip(curv);
			trip.push_back(org2dfs[idx]); // 재귀호출에서 복귀했을 때에도 trip에 추가해 주어야 함
		}
	}
}

// RMQ용 자료구조
int BIT[1<<19];
int base; // BIT에서 실제 데이터가 들어가는 부분의 시작 인덱스

// RMQ (Range Minimum Query)
int RMQ(int start, int end){ // 구간 trip[start~end] 에서 최소값을 리턴

	int result=INF;

	start+=base;
	end+=base;

	while(start<end){
		if(start%2==0) start/=2;
		else{
			result=min2(result,BIT[start]);
			start=(start+1)/2;
		}
		if(end%2==1) end/=2;
		else{
			result=min2(result,BIT[end]);
			end=(end-1)/2;
		}
	}
	if(start==end) result=min2(result,BIT[start]);

	return result;
}

int main(void){

	scanf("%d",&N);
	for(int i=0; i<N-1; i++){
		int v0,v1; // 연결된 두 정점
		scanf("%d %d",&v0,&v1);
		// 양방향 간선 추가 (v0->v1,v1->v0);
		adj[v0].push_back(v1);
		adj[v1].push_back(v0);
	}

	// 각 정점의 레벨 구하기
	lv[1]=1; // 1번 정점이 루트
	p[1]=0;
	q.push(1);

	while(!q.empty()){
		int f=q.front();
		q.pop();
		for(int i=0; i<adj[f].size(); i++){
			int curv=adj[f][i];
			if(lv[curv]==0){
				lv[curv]=lv[f]+1;
				p[curv]=f;
				q.push(curv);
			}
		}
	}

	// dfs 방문 순서에 따른 idx 정하기
	for(int i=1; i<=N; i++) visited[i]=false;
	makeIdxMap(1);

	// trip 생성 (dfs 순서 idx 기준)
	for(int i=1; i<=N; i++){
		visited[i]=false;
		firstPosInTrip[i]=-1;
	}
	makeTrip(1);

	// trip 목록에 대한 RMQ(Range Minimum Query)를 위한 BIT 자료구조 생성
	base=1;
	while(base<trip.size()) base*=2;

	// BIT 초기화
	for(int i=base; i<base*2; i++) BIT[i]=INF;
	for(int i=0; i<trip.size(); i++) BIT[base+i]=trip[i];
	for(int i=base-1; i>=1; i--) BIT[i]=min2(BIT[i*2],BIT[i*2+1]);

	// 쿼리 수행
	scanf("%d",&M);
	for(int i=0; i<M; i++){
		int v0,v1; // LCA를 구하고자 하는 두 정점
		scanf("%d %d",&v0,&v1);

		// trip에 쿼리를 하기 위한 범위 결정
		int rangeStart = firstPosInTrip[v0];
		int rangeEnd = firstPosInTrip[v1];
		if(rangeStart>rangeEnd){
			int tmp=rangeStart;
			rangeStart=rangeEnd;
			rangeEnd=tmp;
		}

		// RMQ 결과로 나오는 공통 조상 idx는 dfs 방문 순서이므로 원래 idx로 변환해야 함
		int ans=dfs2org[RMQ(rangeStart,rangeEnd)];
		printf("%d\n",ans);
	}
	return 0;
}
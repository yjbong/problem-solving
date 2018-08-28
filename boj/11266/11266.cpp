#include <cstdio>
#include <vector>
#define MAXV 10000
#define MAXE 100000
using namespace std;
int V; // 정점의 개수
int E; // 간선의 개수

vector <int> adj[MAXV + 1]; // adj[i] = i번 정점과 연결된 정점들
bool visited[MAXV + 1]; // visited[i] = i번 정점의 방문 여부
int parent[MAXV + 1]; // parent[i] = i번 정점의 부모

int disc[MAXV + 1]; // disc[i] = i번 정점을 발견한 시점
int low[MAXV + 1]; // low[i] = i번 정점의 자손(DFS tree에서 i를 root로 하는 subtree에 속한 정점들 중 i자신이 아닌 정점)과
				   //		   최대 1개의 Back edge로 연결된 정점들 중 최소 disc값 
bool isAP[MAXV + 1]; // isAP[i] = i번 정점이 Articulation Point이면 true

int min2(int a, int b) { return a < b ? a : b; }

void findAP(int u) { // 정점 u를 방문
	static int time = 0;
	int children = 0; // u의 자식 노드 수
	visited[u] = true;
	disc[u] = low[u] = ++time;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (!visited[v]) { // v가 아직 방문되지 않은 경우 --> v는 u의 자식
			children++;
			parent[v] = u;
			findAP(v);

			low[u] = min2(low[u], low[v]);

			// u가 Articulation Point인지 확인
			if (parent[u] < 0) // u가 root인 경우
				if (children > 1) isAP[u] = true; // 자식이 2개 이상이면 단절점
			
			if (parent[u] >= 0 && low[v] >= disc[u]) // u가 root가 아니면서 u의 자식을 루트로 하는 subtree 중 Back edge로 u의 조상과 연결되지 않은 것이 있는 경우
				isAP[u] = true;
		}
		else if (v != parent[u]) { // v가 방문되었으면서 u의 부모 노드가 아님 --> u-v 간선은 Back edge
			low[u] = min2(low[u], disc[v]);
		}
	}
}

int main(void) {
	scanf("%d %d", &V, &E);
	for (int i = 0; i < E; i++) {
		int V0, V1;
		scanf("%d %d", &V0, &V1);
		// 양방향 간선 추가
		adj[V0].push_back(V1);
		adj[V1].push_back(V0);
	}

	for (int i = 1; i <= V; i++) {
		parent[i] = -1;
		visited[i] = isAP[i] = false;
	}

	// AP 찾기
	for(int i=1; i<=V; i++) if(!visited[i]) findAP(i);

	// 답 출력
	int numAP = 0;
	for (int i = 1; i <= V; i++) if (isAP[i]) numAP++;
	printf("%d\n", numAP);
	for (int i = 1; i <= V; i++) if (isAP[i]) printf("%d ", i);
	printf("\n");
	return 0;
}
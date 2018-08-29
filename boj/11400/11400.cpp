#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#define MAXV 100000
#define MAXE 1000000
using namespace std;
int V; // 정점의 개수
int E; // 간선의 개수
typedef pair<int, int> ii;

vector <int> adj[MAXV + 1]; // adj[i] = i번 정점과 연결된 정점들
bool visited[MAXV + 1]; // visited[i] = i번 정점의 방문 여부
int parent[MAXV + 1]; // parent[i] = i번 정점의 부모

int disc[MAXV + 1]; // disc[i] = i번 정점을 발견한 시점
int low[MAXV + 1]; // low[i] = i번 정점의 자손(DFS tree에서 i를 root로 하는 subtree에 속한 정점들 중 i자신이 아닌 정점)과
				   //		   최대 1개의 Back edge로 연결된 정점들 중 최소 disc값 
bool isAP[MAXV + 1]; // isAP[i] = i번 정점이 Articulation Point이면 true
vector <ii> bridge; // bridge = 단절선 목록

int min2(int a, int b) { return a < b ? a : b; }

void findBridge(int u) { // 정점 u를 방문
	static int time = 0;
	int children = 0; // u의 자식 노드 수
	visited[u] = true;
	disc[u] = low[u] = ++time;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (!visited[v]) { // v가 아직 방문되지 않은 경우 --> v는 u의 자식
			children++;
			parent[v] = u;
			findBridge(v);

			low[u] = min2(low[u], low[v]);

			// u가 Bridge인지 확인
			if (adj[u].size() == 1) bridge.push_back(make_pair(u, v)); // u로 갈 수 있는 다른 간선이 없는 경우에 u-v는 Bridge
			else if (low[v] > disc[u]) bridge.push_back(make_pair(u, v)); // u의 자식인 v를 root로 하는 subtree에 속하는 정점들(v제외) 중에서 u 또는 u의 조상으로 가는 경로가 없는 경우에 u-v는 Bridge
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

	// Bridge 찾기
	findBridge(1); // 연결 그래프인 것이 보장되므로 1번만 호출

	// 답 출력
	for (int i = 0; i < bridge.size(); i++) {
		if (bridge[i].first > bridge[i].second) {
			int tmp = bridge[i].first;
			bridge[i].first = bridge[i].second;
			bridge[i].second = tmp;
		}
	}
	sort(bridge.begin(), bridge.end());
	printf("%d\n", bridge.size());
	for (int i = 0; i < bridge.size(); i++) printf("%d %d\n", bridge[i].first, bridge[i].second);

	return 0;
}
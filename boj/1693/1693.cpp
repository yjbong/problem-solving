#include <cstdio>
#include <queue>
#include <vector>
#define INF 1000000000
#define MAXN 100000
#define COLORS 18 // X개의 색깔을 이용하면 2^(X-1) 개 노드에 대해 최소 비용으로 색칠하는 것이 가능 (2^(18-1) = 131072 > 100000 = MAXN)
using namespace std;

int N; // 정점 및 색깔의 개수 (1번 색은 비용 1, 2번 색은 비용 2, ...)
vector <int> adj[MAXN + 1]; // adj[i] = i번 정점과 인접한 정점 목록

queue <int> q;
int dist[MAXN + 1]; // dist[i] = 1번 정점을 루트로 했을 때, i번 정점과 루트와의 거리
int min2(int a, int b) { return a < b ? a : b; }
vector <int> children[MAXN + 1]; // children[i] = i번 정점의 자식 목록
int cache[MAXN + 1][COLORS + 1];
// go(root, rootColor) = root번 정점을 rootColor색으로 칠하고, root번 정점을 루트로 하는 서브트리에 속하는 정점들을 조건을 만족하면서 모두 색칠하기 위한 최소 비용  
int go(int root, int rootColor) {
	if (cache[root][rootColor] >= 0) return cache[root][rootColor];

	int result = rootColor; // root번 정점을 rootColor로 칠하는 비용

	for (int i = 0; i < children[root].size(); i++) {
		int child = children[root][i];
		int childMinVal = INF;
		for (int j = 1; j <= COLORS; j++)
			if(j!=rootColor) childMinVal = min2(childMinVal, go(child, j));
		result += childMinVal;
	}
	return (cache[root][rootColor] = result);
}

int main(void) {

	scanf("%d", &N);
	// 입력되는 그래프는 트리이므로 간선이 N-1개임
	for (int i = 0; i < N - 1; i++) {
		int v0, v1;
		scanf("%d %d", &v0, &v1);
		adj[v0].push_back(v1);
		adj[v1].push_back(v0);
	}

	// 각 정점과 루트와의 거리 계산
	for (int i = 1; i <= N; i++) dist[i] = INF;
	dist[1] = 0;
	q.push(1);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int i = 0; i < adj[cur].size(); i++) {
			int nxt = adj[cur][i];
			if (dist[nxt] > dist[cur] + 1) {
				dist[nxt] = dist[cur] + 1;
				q.push(nxt);
			}
		}
	}

	// 각 정점의 자식 찾기
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < adj[i].size(); j++) {
			if (dist[i] < dist[adj[i][j]]) {
				children[i].push_back(adj[i][j]);
			}
		}
	}

	// DP
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= COLORS; j++) cache[i][j] = -1;
	int ans = INF;
	for (int i = 1; i <= COLORS; i++) ans = min2(ans, go(1, i));

	// 답 출력
	printf("%d\n", ans);
	return 0;
}
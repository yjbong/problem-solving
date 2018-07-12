#include <cstdio>
#include <utility>
#include <vector>
#include <set>
#include <queue>
#define MAX_N 100
#define MAX_M 100
#define INF 1000000000000000ll
using namespace std;
typedef long long ll;
int N; // 도시의 수
int M; // 교통수단의 개수
int src; // 시작 도시
int dst; // 종료 도시

//ll d[MAX_N]; // d[i] = 시작 도시에서 i번 도시까지 갔을 때 가능한 손실(=지출-수입)의 최소값
//ll e[MAX_N][MAX_N]; // e[i][j] = i번 vertex에서 j번 vertex로 이동하기 위한 비용

// 도시를 방문했을 때 얻는 이익을 모델링하기 위해, 각 도시는 2개의 vertex (in, out) 로 구성되어야 한다.
// 이익은 vertex에 대한 것인데, Bellman-Ford 알고리즘에서는 이 값이 edge에 표현되는 것이 자연스럽기 때문이다.
// 통행료는 edge에 대한 것이기 때문에 그대로 가져가면 된다.
// 이 코드에서 i번 도시의 in vertex는 i*2번, out vertex는 i*2+1 번이다.
ll d[MAX_N * 2]; // d[i*2] = 시작 도시에서 i번 도시의 in vertex 까지 갔을 때 가능한 손실(=지출-수입)의 최소값
                  // d[i*2+1] = 시작 도시에서 i번 도시의 out vertex 까지 갔을 때 가능한 손실(=지출-수입)의 최소값

ll e[MAX_N * 2][MAX_N * 2]; // 도시를 in/out vertex로 모델링했기 때문에, vertex 수는 N*2개가 된다.

ll p[MAX_N]; // p[i] = i번 도시를 방문하면 얻는 수입

int main(void) {
	scanf("%d %d %d %d", &N, &src, &dst, &M);

	// edge 배열 초기화
	for (int i = 0; i < N * 2; i++)
		for (int j = 0; j < N * 2; j++)
			e[i][j] = INF;

	for (int i = 0; i < M; i++) {
		int from, to;
		ll cost;
		scanf("%d %d %lld", &from, &to, &cost);
		// 도시 간 이동하는 edge는 출발 도시의 out vertex와 도착 도시의 in vertex를 연결한다.
		if(e[from * 2 + 1][to * 2] > cost) e[from * 2 + 1][to * 2] = cost;
	}

	for (int i = 0; i < N; i++) scanf("%lld", &p[i]);
	for (int i = 0; i < N; i++) {
		// 도시의 in과 out vertex를 연결하는 edge를 만든다.
		e[i * 2][i * 2 + 1] = -p[i];
	}

	// Bellman-Ford
	// d 배열 초기화
	for (int i = 0; i < N * 2; i++) d[i] = INF;
	d[src * 2] = 0; // 시작 도시의 in vertex

	for (int i = 0; i < N * 2 - 1; i++){ // 모든 edge에 대해 (vertex 수-1)회 relaxation
		for (int from = 0; from < N * 2; from++) {
			for (int to = 0; to < N * 2; to++) {
				if (e[from][to] < INF) {
					// relaxation
					if (d[from] < INF && d[to] > d[from] + e[from][to]) {
						d[to] = d[from] + e[from][to];
					}
				}
			}
		}
	}

	// 모든 edge에 대해 relaxation을 한 번 더 시도해 본다.
	// 종료 도시에 갈 수 있으면서 무한대로 돈을 벌 수 있는 경우를 판단
	set <int> negCycle; // negative cycle에 속하는 vertex 목록
	for (int from = 0; from < N * 2; from++) {
		for (int to = 0; to < N * 2; to++) {
			if (e[from][to] < INF) {
				// relaxation
				// N*2번째 iteration에서도 relaxation 이 발생했다면 negative cycle이 있는 것이다.
				if (d[from] < INF && d[to] > d[from] + e[from][to]) {
					d[to] = d[from] + e[from][to]; // from과 to는 negative cycle에 속한다.
					if (negCycle.find(from) == negCycle.end()) negCycle.insert(from);
					if (negCycle.find(to) == negCycle.end()) negCycle.insert(to);
				}
			}
		}
	}
	
	// negCycle에 속하는 vertex 중에서, 종료 도시에 도달할 수 있는 vertex가 있으면 Gee 조건을 만족한다.
	set<int>::iterator it;
	bool gee = false;
	for (it = negCycle.begin(); it != negCycle.end(); it++) {
		// BFS
		queue <int> q;
		bool visited[MAX_N * 2];
		for (int i = 0; i < MAX_N * 2; i++) visited[i] = false;
		q.push(*it);
		visited[*it] = true;

		while (!q.empty()) {
			int f = q.front();
			q.pop();
			for (int i = 0; i < N * 2; i++) {
				if (e[f][i] < INF && visited[i] == false) {
					q.push(i);
					visited[i] = true;
				}
			}
		}

		// negative cycle에 속한 vertex에서 종료 vertex로 이동할 수 있는 경우
		if (visited[dst * 2 + 1]) {
			gee = true;
			break;
		}
	}
	
	// 결과 출력 (종료 도시의 out vertex)
	if (d[dst * 2 + 1] < INF) {
		if (gee) printf("Gee\n"); // 무한대의 돈을 벌 수 있는 경우
		else printf("%d\n", -d[dst * 2 + 1]); // d 배열은 손실을 나타내므로 이익을 나타내려면 음수 기호를 붙여야 한다.
	}
	else printf("gg\n"); // 종료 도시에 도달할 수 없는 경우
	return 0;
}
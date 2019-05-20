#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#define MAX_N 1000
#define MAX_M 2000000
#define MAX_K 100
using namespace std;

typedef struct {
	int dst;
	int time;
}RODE;
typedef pair<int, int> ii; // first: -dist[i], second: i
int N; // 도시의 수
int M; // 도로의 수
int K;

vector <RODE> rode[MAX_N + 1]; // rode[i] = i번 도시와 연결된 도로의 리스트

// heap을 2개 사용하는데, 먼저 각 도시에 대해 K개의 가장 좋은 dist값을 저장하는 maxheap을 만든다.
// 각 dist[i]에 maxheap을 사용하는 이유는,
// 1) K번째 최단 경로를 구하기 위해서는 최대 K개의 best dist값만 있으면 되는데, dijkstra를 하다가 현재 K-th best dist보다
//    더 작은 dist값이 생겨서 이전 K-th best가 불필요해진 경우, 이 값을 빠르게 찾아서 버리기 위한 것이다.
// 2) 어차피 출력할 값은 K번째로 좋은 값이니, maxheap을 쓰면 heap size가 K일 때 그냥 top값을 출력하면 된다.
// 나머지 한 개는 일반적인 dijkstra를 돌리기 위한 minheap이다.

priority_queue <int> dist[MAX_N + 1]; // dist[i] = 출발 도시(1번)에서 i번 도시로 가는 best K개의 거리값
priority_queue <ii> pq;

int main(void) {

	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < M; i++) {
		int from, to, time;
		scanf("%d %d %d", &from, &to, &time);
		RODE r;
		r.dst = to, r.time = time;
		rode[from].push_back(r);
	}

	// 초기화
	dist[1].push(0);
	pq.push(make_pair(0, 1));

	// dijkstra
	while (!pq.empty()) {
		ii f = pq.top(); pq.pop();
		int fdist = -f.first;
		int fcity = f.second;
		for (int i = 0; i < rode[fcity].size(); i++) {
			int ccity = rode[fcity][i].dst;
			int ctime = rode[fcity][i].time;
			// 현재 도시의 dist가 갱신되는 경우 (dist의 갯수가 K 미만이거나, K-th best dist가 갱신될 필요가 있는 경우)
			if (dist[ccity].size() < K || dist[ccity].top() > fdist + ctime) {
				if (dist[ccity].size() >= K) dist[ccity].pop();
				dist[ccity].push(fdist + ctime);
				pq.push(make_pair(-(fdist + ctime), ccity));
			}
		}
	}

	// 답 출력
	for (int i = 1; i <= N; i++) {
		if (dist[i].size() < K) printf("-1\n"); // K번째 최단경로가 존재하지 않는 경우
		else printf("%d\n", dist[i].top());
	}

	return 0;
}
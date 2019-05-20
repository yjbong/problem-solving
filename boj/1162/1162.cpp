#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
#define MAXN 10000
#define MAXK 20
#define INF 1000000000000000ll
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; 
typedef pair<ll, ii> iii;

int N; // 도시의 수
int M; // 도로의 수
int K; // 포장할 도로의 수
vector<pair<int, ll> > road[MAXN + 1]; // road[i] = i번 도시에 인접한 도로의 정보 (first = 연결된 도시 번호, second = 소요시간)
ll D[MAXN+1][MAXK + 1]; // D[i][j] = j개의 도로를 포장했을 때, 출발 도시에서 i번 도시까지 가는 최소 비용
priority_queue <iii> pq; // first = -D[i][j], second.first = 도시 번호(i), second.second = 포장한 도로의 수(j)

int main(void) {
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < M; i++) {
		int city1, city2;
		ll time;
		scanf("%d %d %lld", &city1, &city2, &time);
		// 양방향 도로 추가
		road[city1].push_back(make_pair(city2, time));
		road[city2].push_back(make_pair(city1, time));
	}

	// DP 배열 초기화
	for (int i = 1; i <= N; i++)
		for (int j = 0; j <= K; j++) D[i][j] = INF;

	// 출발 도시는 1번 도시
	D[1][0] = 0;
	pq.push(make_pair(-D[1][0], make_pair(1, 0)));

    // Dijkstra
	while (!pq.empty()) {
		iii f = pq.top(); pq.pop();

		ll fdist = -f.first;
		int fcity = f.second.first;
		int fk = f.second.second;

		for (int i = 0; i < road[fcity].size(); i++) {
			int nxtcity = road[fcity][i].first;
			long long time = road[fcity][i].second;

			// nxtCity로 이동하는 도로를 포장하는 경우
			if (fk < K) { // 도로를 더 포장할 수 있는 경우
				if (D[nxtcity][fk + 1] > D[fcity][fk]) {
					D[nxtcity][fk + 1] = D[fcity][fk];
					pq.push(make_pair(-D[nxtcity][fk + 1], make_pair(nxtcity, fk + 1)));
				}
			}
			// 포장하지 않는 경우
			if (D[nxtcity][fk] > D[fcity][fk] + time) {
				D[nxtcity][fk] = D[fcity][fk] + time;
				pq.push(make_pair(-D[nxtcity][fk], make_pair(nxtcity, fk)));
			}
		}
	}
	
	// 도착 도시는 N번 도시
	ll ans = INF;
	for (int i = 0; i <= K; i++) if (ans > D[N][i]) ans = D[N][i];
	printf("%lld\n", ans);

	return 0;
}
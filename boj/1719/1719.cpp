#include <cstdio>
#include <cstdlib>
#include <ctime>
#define MAXN 200 
#define INF 1000000000
int N; // 집하장의 개수 (1 ~ N번 집하장)
int M; // 경로의 개수
int w[MAXN+1][MAXN+1]; // w[i][j] = i번 정점에서 j번 정점으로 이동하는 간선의 비용
int d[MAXN+1][MAXN+1]; // d[i][j] = i번 정점에서 j번 정점으로 이동하는 최단 거리
int p[MAXN+1][MAXN+1]; // p[i][j] = i번 정점에서 j번 정점으로 이동하는 최단 경로에서 정점 j 바로 전에 거쳐야 하는 정점

void FloydWarshall(int N) {

	// d 배열의 초기화
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			d[i][j] = i == j ? 0 : w[i][j];

	// p 배열의 초기화
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			p[i][j] = i; // p의 정의에 따라 i~j 의 경로에서 i,j 외의 경유점이 없는 경우 p[i][j] = i 이기 때문

	// Floyd-Warshall
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				// 정점 k를 경유하는 것이 빠를 경우
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j]; // d 업데이트
					p[i][j] = p[k][j]; // p 업데이트
				}
			}
		}
	}
}

// 정점 i에서 j로의 최단 경로를 출력
void printShortestPath(int i, int j) {
	if (i != j)
		printShortestPath(i, p[i][j]);
	printf("%d\n", j);
}

int main(void) {

	// 그래프 입력
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) w[i][j] = INF;

	for (int i = 0; i < M; i++) {
		int v0, v1, cost;
		scanf("%d %d %d", &v0, &v1, &cost);
		// 양방향 간선임
		w[v0][v1] = w[v1][v0] = cost;
	}

	// Floyd-Warshall 알고리즘 수행
	FloydWarshall(N);

	// 문제에서는 i->j로의 최단경로 중 2번째로 지나게 되는 (출발점 i 바로 다음에 경유할) 정점을 구해야 한다.
	// 그리고 구해놓은 p[i][j] 는 도착점 j 직전에 경유하는 정점을 나타낸다.
	// 그런데 이 문제에서 모든 간선은 방향성이 없으므로, i->j의 경로는 j->i의 경로를 단순히 역순으로 한 것이다.
	// 즉, p[j][i] 가 i->j로의 최단경로 중 2번째로 지나는 정점을 나타낸다고 볼 수 있다.

	// 답 출력
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) printf("- ");
			else printf("%d ", p[j][i]);
		}
		printf("\n");
	}

	return 0;
}
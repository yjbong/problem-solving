#include <cstdio>
#include <map>
#include <utility>
#include <queue>
#include <vector>

#define MAX_X 1000000
#define MAX_Y 200000
#define MAX_N 50000
#define INF 1000000000
using namespace std;
typedef struct {
	int y;
	int x;
}POINT;

int N; // 홈의 개수
int T; // 정상의 높이 (= y좌표의 최대값)
POINT p[MAX_N + 1]; // p[i] = i번째 홈의 위치
map<int, int> sameY[MAX_Y + 1]; // sameY[i] = y좌표가 i 인 홈들의 집합 (각 원소의 first(key): x좌표, second: p에서의 index)
int d[MAX_N + 1]; // 시작점(0,0)에서 p[i]로 가기 위한 최소 이동 횟수
bool adjChecked[MAX_N + 1];
vector <int> adj[MAX_N + 1]; // adj[i] = p[i]에서부터 이동 가능한 홈들의 index

int main(void) {

	scanf("%d %d", &N, &T);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &p[i].x, &p[i].y); // 현재 홈의 좌표 입력
		d[i] = INF; // 현재 홈에 대한 d 초기화
		sameY[p[i].y].insert(make_pair(p[i].x, i)); // sameY에 현재 홈을 추가
		adjChecked[i] = false;
	}

	// 시작점을 추가
	p[N].x = 0, p[N].y = 0;
	d[N] = 0;
	sameY[p[N].y].insert(make_pair(p[N].x, N));
	adjChecked[N] = false;

	// BFS로 d 배열 업데이트
	queue <int> q;
	q.push(N); // 시작점을 queue에 추가
	while (!q.empty()) {
		int f = q.front(); q.pop();
		int fy = p[f].y, fx = p[f].x;
		// (fy,fx)에서 이동할 수 있는 홈들을 찾음 (최대 5*5=25개)
		if (adjChecked[f]==false) { // adj[f]를 아직 구하지 않은 경우
			for (int i = -2; i <= 2; i++) { // i -> y변위
				for (int j = -2; j <= 2; j++) { // j -> x변위
					if (fy + i >= 0 && fy + i <= T) {
						map<int, int>::iterator it;
						it = sameY[fy + i].find(fx + j);
						if (it != sameY[fy + i].end()) adj[f].push_back(it->second);
					}
				}
			}
			adjChecked[f] = true;
		}

		// (fy,fx)에서 이동할 수 있는 홈들의 d값 업데이트
		for (int i = 0; i < adj[f].size(); i++) {
			if (d[adj[f][i]] > d[f] + 1) {
				d[adj[f][i]] = d[f] + 1;
				q.push(adj[f][i]);
			}
		}
	}
	
	// 답 출력
	int ans = INF;
	for (int i = 0; i <= N; i++)
		if (p[i].y >= T && ans > d[i]) ans = d[i];
	
	if (ans < INF) printf("%d\n", ans);
	else printf("-1\n");

	return 0;
}
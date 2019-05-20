#include <cstdio>
#include <queue>
#include <utility>
#define INF 1000000000
using namespace std;
typedef pair<int, int> ii;
int n, m; // 섬의 크기(n행 m열)
char a[3000][3000+1];
int dist[3000][3000];
const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,1,-1 };
queue <ii> q;
int ans;
int main(void) {
	scanf("%d %d\n", &n, &m);
	for (int i = 0; i<n; i++)
		scanf("%s\n", a[i]);

	for (int i = 0; i<n; i++)
		for (int j = 0; j<m; j++)
			dist[i][j] = INF;
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			if (a[i][j] == '2') { // 딱다구리의 위치
				dist[i][j] = 0;
				q.push(make_pair(i, j));
				goto out;
			}
		}
	}
out:

	while (!q.empty()) {
		ii f = q.front(); q.pop();
		int fy = f.first, fx = f.second;

		for (int k = 0; k<4; k++) {
			int cy = fy + dy[k], cx = fx + dx[k];
			if (cy >= 0 && cy<n && cx >= 0 && cx<m && a[cy][cx] != '1' && dist[cy][cx]>dist[fy][fx] + 1) {
				dist[cy][cx] = dist[fy][fx] + 1;
				q.push(make_pair(cy, cx));
			}
		}
	}

	ans = INF;
	for (int i = 0; i<n; i++)
		for (int j = 0; j<m; j++)
			if (a[i][j]>'2' && ans>dist[i][j]) ans = dist[i][j];

	if (ans<INF) printf("TAK %d\n", ans);
	else printf("NIE\n");
	return 0;
}
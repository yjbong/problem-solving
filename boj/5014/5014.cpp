#include <cstdio>
#include <queue>
#define MAXF 1000000
#define INF 1000000000
using namespace std;

queue <int> q;
int d[MAXF+1]; // d[i] = 출발층에서 i층으로 가기 위해 버튼을 눌러야 하는 최소 횟수

int F, S, G, U, D;

int main(void) {

	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
	for (int i = 1; i <= F; i++) d[i] = INF;

	// BFS
	d[S] = 0;
	q.push(S);
	while (!q.empty()) {
		int f = q.front(); q.pop();
		// f층에서 위로 U층만큼 이동
		if (f + U <= F && d[f + U] > d[f] + 1) {
			d[f + U] = d[f] + 1;
			q.push(f + U);
		}
		// f층에서 아래로 D층만큼 이동
		if (f - D >= 1 && d[f - D] > d[f] + 1) {
			d[f - D] = d[f] + 1;
			q.push(f - D);
		}
	}

	// 답 출력
	if (d[G] < INF) printf("%d\n", d[G]);
	else printf("use the stairs\n");

	return 0;
}
#include <cstdio>
#define MAXN 50
#define MAXH 100
int n; // stack의 수
int h[MAXN]; // h[i] = i번째 stack의 높이
int blocks; // 전체 블록 수

int main(void) {
	int setNum = 1;
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		blocks = 0;
		for (int i = 0; i < n; i++) scanf("%d", &h[i]);
		for (int i = 0; i < n; i++) blocks += h[i];
		int ans = 0;

		for (int i = 0; i < n; i++) if (h[i] > blocks / n) ans += h[i] - (blocks / n);

		printf("Set #%d\n", setNum);
		printf("The minimum number of moves is %d.\n\n", ans);
		setNum++;
	}
	return 0;
}
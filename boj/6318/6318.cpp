#include <cstdio>
#define MAXN 50
#define MAXH 100
int n; // stack�� ��
int h[MAXN]; // h[i] = i��° stack�� ����
int blocks; // ��ü ��� ��

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
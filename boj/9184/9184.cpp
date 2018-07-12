#include <cstdio>
#define INF 1000000000
int cache[21][21][21];
int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);
	if (a < b && b < c) {
		if (cache[a][b][c] < INF) return cache[a][b][c];
		return (cache[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c));
	}

	if (cache[a][b][c] < INF) return cache[a][b][c];
	return (cache[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1));
}

int main(void) {
	for (int i = 0; i <= 20; i++)
	for (int j = 0; j <= 20; j++)
	for (int k = 0; k <= 20; k++)
		cache[i][j][k] = INF;

	while (1) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == -1 && b == -1 && c == -1) break;
		printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
	}
	return 0;
}
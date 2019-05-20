#include <cstdio>
#define MAX_N 1000
#define MAX_M 1000
int N, M;
int cache[MAX_N][MAX_M];
int c[MAX_N][MAX_M]; // c[i][j] = i,j 에 있는 캔디의 수

int max2(int a, int b) { return a > b ? a : b; }

int candies(int row, int col) {

	if (cache[row][col] >= 0) return cache[row][col];
	int premax = 0;
	if (row > 0) premax = max2(premax, candies(row - 1, col));
	if (col > 0) premax = max2(premax, candies(row, col - 1));
	if (row > 0 && col > 0) premax = max2(premax, candies(row - 1, col - 1));

	return cache[row][col] = premax + c[row][col];
}

int main(void) {

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) scanf("%d", &c[i][j]);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) cache[i][j] = -1;

	printf("%d\n", candies(N - 1, M - 1));
	return 0;
}
#include <cstdio>
#define MAX_N 500
#define INF 2147483647
int N; // 행렬의 개수
int r[MAX_N]; // r[i] = 행렬 i의 행의 수
int c[MAX_N]; // c[i] = 행렬 i의 열의 수
int D[MAX_N][MAX_N]; // D[i][j] = i번 행렬부터 j번 행렬까지를 행렬곱할 때 필요한 최소 곱셈 횟수

int min2(int a, int b) { return a < b ? a : b; }

int mulCount(int left, int right) {
	if (D[left][right] >= 0) return D[left][right];
	
	if (left == right) return D[left][right] = 0;
	else if (left + 1 == right) return D[left][right] = r[left] * c[left] * c[right];

	int ret = INF;
	for (int k = left; k < right; k++)
		ret = min2(ret, mulCount(left, k) + mulCount(k + 1, right) + r[left] * c[k] * c[right]);

	return D[left][right] = ret;
}

int main(void) {

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d %d", &r[i], &c[i]);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			D[i][j] = -1;

	printf("%d\n", mulCount(0, N - 1));
	return 0;
}
#include <cstdio>
#define MAXN 1000
#define MAXM 1000
#define INF 1000000000
int N; // ��Ʈ�� ���� ����� ��
int M; // ��Ʈ�� ���� ĭ�� ����
int A[MAXN]; // A[i] = i��° ����� �̸��� ����

int min2(int a, int b) { return a < b ? a : b; }

// go(idx, col) = idx������ N�������� ����� ��Ʈ�� ����� �ϰ�, ���� ��Ʈ�� �࿡�� ó������ ��� �ִ� ��(���� ������ �� �� ����)��
//				  col���� ��, ������ ������ �ּҰ� (col==M �̶�� ���� �ٿ� �� ĭ�� ���� ����)
int cache[MAXN+1][MAXM+1];

int go(int idx, int col) {
	if (idx >= N) return 0;
	if (cache[idx][col] >= 0) return cache[idx][col];
	int result = INF;
	// case 1: idx�� ����� �̸��� ���� �࿡ �̾ ����
	if (col > 0) { // ���� �࿡ �ٸ� �̸��� ���� ������ �ִ� ��� --> ���� ���� �̸� �ڿ� �� ĭ ���� �Ῡ ��
		if (col + 1 + A[idx] <= M) result = min2(result, go(idx + 1, col + 1 + A[idx]));
	}
	else result = min2(result, go(idx + 1, A[idx])); // �׷��� �ʴٸ� ó��(0��)���� ���� ��

	// case 2: idx�� ����� �̸��� �� �ٿ� ���� ��� --> ���� �ٿ� ���� ĭ ���� ������ŭ ���� �߰�
	result = min2(result, go(idx + 1, A[idx]) + (M - col)*(M - col));

	return cache[idx][col] = result;
}

int main(void) {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);

	// cache �ʱ�ȭ
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= M; j++) cache[i][j] = -1;

	// �� ���
	printf("%d\n", go(0, 0));

	return 0;
}
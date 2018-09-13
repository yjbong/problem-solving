#include <cstdio>
#include <cstdlib>
#include <ctime>
#define MAXN 200 
#define INF 1000000000
int N; // �������� ���� (1 ~ N�� ������)
int M; // ����� ����
int w[MAXN+1][MAXN+1]; // w[i][j] = i�� �������� j�� �������� �̵��ϴ� ������ ���
int d[MAXN+1][MAXN+1]; // d[i][j] = i�� �������� j�� �������� �̵��ϴ� �ִ� �Ÿ�
int p[MAXN+1][MAXN+1]; // p[i][j] = i�� �������� j�� �������� �̵��ϴ� �ִ� ��ο��� ���� j �ٷ� ���� ���ľ� �ϴ� ����

void FloydWarshall(int N) {

	// d �迭�� �ʱ�ȭ
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			d[i][j] = i == j ? 0 : w[i][j];

	// p �迭�� �ʱ�ȭ
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			p[i][j] = i; // p�� ���ǿ� ���� i~j �� ��ο��� i,j ���� �������� ���� ��� p[i][j] = i �̱� ����

	// Floyd-Warshall
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				// ���� k�� �����ϴ� ���� ���� ���
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j]; // d ������Ʈ
					p[i][j] = p[k][j]; // p ������Ʈ
				}
			}
		}
	}
}

// ���� i���� j���� �ִ� ��θ� ���
void printShortestPath(int i, int j) {
	if (i != j)
		printShortestPath(i, p[i][j]);
	printf("%d\n", j);
}

int main(void) {

	// �׷��� �Է�
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) w[i][j] = INF;

	for (int i = 0; i < M; i++) {
		int v0, v1, cost;
		scanf("%d %d %d", &v0, &v1, &cost);
		// ����� ������
		w[v0][v1] = w[v1][v0] = cost;
	}

	// Floyd-Warshall �˰��� ����
	FloydWarshall(N);

	// ���������� i->j���� �ִܰ�� �� 2��°�� ������ �Ǵ� (����� i �ٷ� ������ ������) ������ ���ؾ� �Ѵ�.
	// �׸��� ���س��� p[i][j] �� ������ j ������ �����ϴ� ������ ��Ÿ����.
	// �׷��� �� �������� ��� ������ ���⼺�� �����Ƿ�, i->j�� ��δ� j->i�� ��θ� �ܼ��� �������� �� ���̴�.
	// ��, p[j][i] �� i->j���� �ִܰ�� �� 2��°�� ������ ������ ��Ÿ���ٰ� �� �� �ִ�.

	// �� ���
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) printf("- ");
			else printf("%d ", p[j][i]);
		}
		printf("\n");
	}

	return 0;
}
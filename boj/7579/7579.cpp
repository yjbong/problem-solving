#include <cstdio>
#define MAXN 100
#define MAXC 100
int N; // Ȱ��ȭ�� App�� ��
int M; // �ʿ��� �޸� ũ��(����Ʈ)
int m[MAXN+1]; // m[i] = i�� App�� ��� ���� �޸� ũ��(����Ʈ)
int c[MAXN+1]; // c[i] = i�� App�� ��Ȱ��ȭ���� ���� ���

int max2(int a, int b) { return a > b ? a : b; }

// �� ������ knapsack�̶� �����ϰ� Ǭ��.
// ���� Ȱ��ȭ�� App�� �� -> item�� ��
// � App�� ��Ȱ��ȭ ���� ���� ��� -> �ش� item�� ����
// � App�� ��Ȱ��ȭ ���� �� Ȯ���ϴ� �޸� ũ�� -> �ش� item�� ��ġ
// ����Ϸ��� App�� �� ��Ȱ��ȭ ��� -> �賶�� capacity

int d[MAXN + 1][MAXN*MAXC + 1]; // d[i][j] = 0~i�� item�� ���� ��, �賶�� �뷮�� j�� �� ���� �� �ִ� �ִ� ��ġ�� ��
								//			(= 0~i�� App�� ����, �߻��ϴ� App�� �� ��Ȱ��ȭ ����� �ִ� j�� ������ �� Ȯ���� �� �ִ� �ִ� �޸� ũ��)

int main(void) {

	// �Է�
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) scanf("%d", &m[i]);
	int csum = 0;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &c[i]);
		csum += c[i];
	}

	// 0-1 knapsack
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= csum; j++) {
			d[i][j] = d[i - 1][j]; // i�� item�� �������� ���� ��� (= i�� App�� ��Ȱ��ȭ���� �ʴ� ���)
			if (j >= c[i]) d[i][j] = max2(d[i][j], d[i - 1][j - c[i]] + m[i]); // i�� item�� �����ϴ� ��� (= i�� App�� ��Ȱ��ȭ�ϴ� ���)
		}
	}
	
	// �� ���
	int ans = -1;
	for (int j = 0; j <= csum; j++) {
		if (d[N][j] >= M) {
			ans = j; // j = M �̻��� �޸𸮸� Ȯ���� �� �ִ� �ּ��� ��Ȱ��ȭ ��� ���Ѱ� 
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}
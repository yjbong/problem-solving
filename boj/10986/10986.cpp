#include <cstdio>
#define MAXN 1000000
#define MAXM 1000

int N; // ������ ����
int M; // modular num
int A[MAXN]; // ����
int S[MAXM]; // S[i] = ������� ���� Prefix sum �� �������� i�� ���� ����

int main(void) {

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);

	int pSum = 0;
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		pSum = (pSum + A[i]) % M;
		if (pSum == 0) ans++; // A[0 ~ i] �� �������� M���� ������ ������
		ans += S[pSum]; // 0 < j < i �� j�� ���Ͽ� A[j ~ i] �� �������� M���� �������� ������ ������
		S[pSum]++;
	}
	// �� ���
	printf("%lld\n", ans);
	return 0;
}
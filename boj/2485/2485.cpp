#include <cstdio>
#include <algorithm>
#define MAXN 100000
using namespace std;

int N; // �̹� �ɾ��� �ִ� ���μ��� ��
int P[MAXN]; // P[i] = i��° ���μ��� ��ġ
int S[MAXN - 1]; // S[i] = i��° ���μ��� i+1��° ���μ��� ����

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main(void) {

	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &P[i]);
	sort(P, P + N);

	// ���� ���� ���� ��� (N���� ������ �ִٸ� N-1���� ������ ����)
	for (int i = 0; i < N - 1; i++) S[i] = P[i + 1] - P[i];
	
	// ���ݵ��� �ִ����� ���
	int gcdS = S[0];
	for (int i = 1; i < N - 1; i++) gcdS = gcd(gcdS, S[i]);

	// �� ���
	int ans = 0;
	for (int i = 0; i < N - 1; i++) ans += S[i] / gcdS - 1;

	printf("%d\n", ans);

	return 0;
}
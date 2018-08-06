#include <cstdio>
#define MAXN 1000000
int s[1450]; // s[i] = 1+2+3+...+i
int ans[MAXN + 1]; // ans[i] = i���� ���� ���� ���� ��
int main(void) {
	s[0] = 0;
	for (int i = 1; i < 1450; i++) s[i] = s[i - 1] + i;

	for (int i = 1; i <= MAXN; i++) { // �Է����� ���� �� �ִ� ��� i�� ���Ͽ�,
		for (int j = 1; j < 1450; j++) { // �������� ���� j�� �����ϴ� ��츦 ����� ����.
			if (i - s[j - 1] < 0) break;
			if (((i - s[j - 1]) / j >= 2) && ((i - s[j - 1]) % j == 0)) ans[i]++; // ���� �� ���� ������ 2�̹Ƿ� ���� 2�̻��̶�� ������ �ٴ´�.
		}
	}

	while (1) {
		int N;
		scanf("%d", &N);
		if (N == 0) break;
		printf("%d\n", ans[N]); // �׽�Ʈ ���̽����� �̸� ����� ���� ����Ѵ�.
	}
	
	return 0;
}
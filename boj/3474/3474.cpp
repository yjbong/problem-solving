#include <cstdio>
int main(void) {
	int T;
	scanf("%d", &T);
	while (T--) {
		int N, tmp;
		scanf("%d", &N);

		// N! �� ���μ��������� �� 2�� �¼� ����
		tmp = N;
		int twos = 0;
		while (tmp > 0) {
			twos += tmp / 2;
			tmp /= 2;
		}
		// N! �� ���μ��������� �� 5�� �¼� ����
		tmp = N;
		int fives = 0;
		while (tmp > 0) {
			fives += tmp / 5;
			tmp /= 5;
		}
		// �� ���
		if (twos < fives) printf("%d\n", twos);
		else printf("%d\n", fives);
	}
	return 0;
}
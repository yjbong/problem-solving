#include <cstdio>
#include <cstring>
int T;
char N[100001 + 1];
int L; // N�� �ڸ���
int x, y;
bool D[1000001]; // D[i]=N�� ������ L-i�� �ڸ�(N[i~L-1])�� ���� x�� L-i�� �̾���� ������ ũ�ų� ������ true, ������ false

int main() {
	scanf("%d", &T);
	for (int z = 1; z <= T; z++) {
		scanf("%s %d %d", N, &x, &y);
		L = strlen(N);
		printf("#%d ", z);

		// D ���
		D[L - 1] = (N[L - 1] - '0' >= x);
		for (int i = L - 2; i >= 0; i--) {
			if (N[i] - '0'>x) D[i] = true;
			else if (N[i] - '0'<x) D[i] = false;
			else D[i] = D[i + 1];
		}

		bool ignore = false; // �� ���� true�� N�� ��� ���ֵ� ������� ��� y�� ä���.
		bool nonzero = false; // nonzero�� ���ڸ� ����� ���� ������ true

		for (int i = 0; i<L; i++) {
			if (ignore) { printf("%d", y); nonzero = true; continue; }
			if (N[i] - '0'>y) { printf("%d", y); nonzero = true; ignore = true; }
			else if (N[i] - '0' == y) {
				if (i == L - 1 || D[i + 1]) { printf("%d", y); nonzero = true; }
				else {
					// x�� 0 ���� Ȯ���ϰ� ����Ѵ�.
					if (nonzero || x>0) { printf("%d", x); nonzero = true; }
					ignore = true;
				}
			}
			else if (N[i] - '0'>x) {
				if (nonzero || x>0) { printf("%d", x); nonzero = true; }
				ignore = true;
			}
			else if (N[i] - '0' == x) {
				if (i == L - 1 || D[i + 1]) {
					if (nonzero || x>0) { printf("%d", x); nonzero = true; }
				}
				else ignore = true;
			}
			else ignore = true;
		}

		// ������ ���� �Ŀ��� nonzero==false��� ���� ������ ���� ���ٴ� ���̴�.
		if (!nonzero) printf("-1");
		printf("\n");
	}
	return 0;
}
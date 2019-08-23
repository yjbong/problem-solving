#include <cstdio>
#include <cstring>
int T;
char N[100001 + 1];
int L; // N의 자릿수
int x, y;
bool D[1000001]; // D[i]=N의 마지막 L-i개 자리(N[i~L-1])가 숫자 x를 L-i개 이어붙인 수보다 크거나 같으면 true, 작으면 false

int main() {
	scanf("%d", &T);
	for (int z = 1; z <= T; z++) {
		scanf("%s %d %d", N, &x, &y);
		L = strlen(N);
		printf("#%d ", z);

		// D 계산
		D[L - 1] = (N[L - 1] - '0' >= x);
		for (int i = L - 2; i >= 0; i--) {
			if (N[i] - '0'>x) D[i] = true;
			else if (N[i] - '0'<x) D[i] = false;
			else D[i] = D[i + 1];
		}

		bool ignore = false; // 이 값이 true면 N이 어떻게 되있든 상관없이 모두 y로 채운다.
		bool nonzero = false; // nonzero인 숫자를 출력한 적이 있으면 true

		for (int i = 0; i<L; i++) {
			if (ignore) { printf("%d", y); nonzero = true; continue; }
			if (N[i] - '0'>y) { printf("%d", y); nonzero = true; ignore = true; }
			else if (N[i] - '0' == y) {
				if (i == L - 1 || D[i + 1]) { printf("%d", y); nonzero = true; }
				else {
					// x는 0 인지 확인하고 출력한다.
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

		// 루프가 끝난 후에도 nonzero==false라는 것은 가능한 값이 없다는 뜻이다.
		if (!nonzero) printf("-1");
		printf("\n");
	}
	return 0;
}
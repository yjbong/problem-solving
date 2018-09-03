#include <cstdio>
int T, N;
int main(void) {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		int SQ = N * N;
		while (N > 0 && (N % 10 == SQ % 10)) { N /= 10; SQ /= 10; }
		if (N == 0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
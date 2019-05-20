#include <cstdio>
#include <cstring>
#include <cmath>
int T;
char S[10001];
int len;
int N;
int main(void) {
	scanf("%d\n", &T);
	while (T--) {
		gets(S);
		len = strlen(S);
		N = (int)sqrt(len);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int r = j, c = N - 1 - i;
				printf("%c", S[r * N + c]);
			}
		}
		printf("\n");
	}
	return 0;
}
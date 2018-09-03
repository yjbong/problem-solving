#include <cstdio>
#define MAXN 1000000
#define MOD 1000000009ll
long long D[MAXN + 1];
int main(void) {
	D[0] = 1;
	D[1] = 1;
	D[2] = 2;
	for (int i = 3; i <= MAXN; i++)
		D[i] = (D[i - 1] + D[i - 2] + D[i - 3]) % MOD;

	int T;
	scanf("%d", &T);
	while (T--) {
		int N;
		scanf("%d", &N);
		printf("%lld\n", D[N]);
	}
	return 0;
}
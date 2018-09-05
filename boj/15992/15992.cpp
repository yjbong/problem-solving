#include <cstdio>
#define MAXN 1000
#define MOD 1000000009ll
typedef long long ll;
ll D[MAXN+1][MAXN+1]; // D[i][j] = i를 1,2,3으로 나타내는 경우의 수. 단, 이 때 사용한 수의 개수가 j개.

int main(void) {

	D[0][0] = 1;
	D[1][1] = 1;
	D[2][1] = 1, D[2][2] = 1;
	for (int i = 3; i <= MAXN; i++)
		for (int j = 1; j <= i; j++)
			D[i][j] = (D[i - 1][j - 1] + D[i - 2][j - 1] + D[i - 3][j - 1]) % MOD;

	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m;
		scanf("%d %d", &n, &m);
		printf("%lld\n", D[n][m]);
	}

	return 0;
}
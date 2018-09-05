#include <cstdio>
#define MAXN 100000
#define MOD 1000000009ll
typedef long long ll;
ll D[MAXN + 1][4]; // D[i][j] = 1,2,3의 합으로 만든 수가 i이고 마지막에 사용한 수가 j인 경우의 수
int main(void) {
	D[0][0] = 1;
	D[1][1] = 1; // 1
	D[2][2] = 1; // 2
	for (int i = 3; i <= MAXN; i++) {
		for (int j = 1; j <= 3; j++) {
			for (int k = 0; k <= 3; k++) {
				if (k != j) D[i][j] = (D[i][j] + D[i - j][k]) % MOD;
			}
		}
	}

	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		ll ans = (D[n][1] + D[n][2] + D[n][3]) % MOD;;
		printf("%lld\n", ans);
	}

	return 0;
}
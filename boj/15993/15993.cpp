#include <cstdio>
#define MAXN 100000
#define MOD 1000000009ll
typedef long long ll;
ll D[MAXN + 1][2]; // D[i][0] = i를 1,2,3의 합으로 만드는 경우의 수. 단, 사용한 수의 개수가 짝수
				   // D[i][1] = i를 1,2,3의 합으로 만드는 경우의 수. 단, 사용한 수의 개수가 홀수

int main(void) {
	D[0][0] = 1;
	D[1][1] = 1;
	D[2][0] = 1, D[2][1] = 1;
	for (int i = 3; i <= MAXN; i++) {
		D[i][0] = (D[i - 1][1] + D[i - 2][1] + D[i - 3][1]) % MOD;
		D[i][1] = (D[i - 1][0] + D[i - 2][0] + D[i - 3][0]) % MOD;
	}

	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		printf("%lld %lld\n", D[n][1], D[n][0]);
	}

	return 0;
}
#include <cstdio>
#define MAXN 100000
#define MOD 1000000009ll
typedef long long ll;
ll D[MAXN/2 + 1]; // D[i] = i를 1,2,3의 합으로 나타내는 경우의 수

int main(void) {

	D[0] = 1;
	D[1] = 1;
	D[2] = 2;
	for (int i = 3; i <= MAXN / 2; i++)
		D[i] = (D[i - 1] + D[i - 2] + D[i - 3]) % MOD;
	
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);

		ll ans = 0;
		// Case 1. 중앙 수가 없는 경우 (더해지는 수의 개수가 짝수)
		if (n % 2 == 0) ans = (ans + D[n / 2]) % MOD;
		// Case 2. 중앙 수가 1인 경우
		if (n - 1 >= 0 && (n - 1) % 2 == 0) ans = (ans + D[(n - 1) / 2]) % MOD;
		// Case 3. 중앙 수가 2인 경우
		if (n - 2 >= 0 && (n - 2) % 2 == 0) ans = (ans + D[(n - 2) / 2]) % MOD;
		// Case 4. 중앙 수가 3인 경우
		if (n - 3 >= 0 && (n - 3) % 2 == 0) ans = (ans + D[(n - 3) / 2]) % MOD;
		
		printf("%lld\n", ans);
	}

	return 0;
}
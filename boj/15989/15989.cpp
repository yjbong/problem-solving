#include <cstdio>
#define MAXN 10000
typedef long long ll;
int cache[MAXN + 1][4];
// go(num, c) = num을 c 이하의 자연수들의 합으로 나타내는 경우의 수
ll go(int num, int c) {
	if (c == 0) return num == 0 ? 1 : 0;
	if (cache[num][c] >= 0) return cache[num][c];
	ll result = 0;
	for (int i = 0; i*c <= num; i++)
		result += go(num - i * c, c - 1);
	return (cache[num][c] = result);
}
int main(void) {

	for (int i = 0; i <= MAXN; i++)
		for (int j = 0; j <= 3; j++)
			cache[i][j] = -1;

	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		printf("%lld\n", go(n, 3));
	}
	return 0;
}
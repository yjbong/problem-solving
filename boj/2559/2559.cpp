#include <cstdio>
int N, K;
int A[100000];
int main(void) {

	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	int ans, sum = 0;
	for (int i = 0; i < K; i++) sum += A[i];
	ans = sum;
	for (int i = K; i < N; i++) {
		sum += A[i] - A[i - K];
		if (ans < sum) ans = sum;
	}
	printf("%d\n", ans);
	return 0;
}
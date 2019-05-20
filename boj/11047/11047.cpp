#include <cstdio>
int N; // 동전의 종류
int K; // 목표금액
int A[10]; // A[i] = i번 동전의 액면가

int main(void) {

	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);

	int ans = 0;
	for (int i = N - 1; i >= 0; i--) {
		ans += K / A[i];
		K %= A[i];
	}
	printf("%d\n", ans);
	
	return 0;
}
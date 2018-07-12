#include <cstdio>
#define MAXN 1000000
#define MAXM 1000000
int N; // 배열 A의 크기
int M; // 배열 B의 크기
int A[MAXN];
int B[MAXM];
int C[MAXN + MAXM]; // 결과 배열

int main(void) {

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	for (int i = 0; i < M; i++) scanf("%d", &B[i]);

	// 배열 A와 B를 합쳐 배열 C를 만듬
	for (int i = 0, j = 0, k = 0; k < N + M; k++) {
		if (i < N && j < M) {
			if (A[i] < B[j]) C[k] = A[i++];
			else C[k] = B[j++];
		}
		else if (i < N) C[k] = A[i++];
		else C[k] = B[j++];
	}
	// C 출력
	for (int i = 0; i < N + M; i++) printf("%d ", C[i]);
	printf("\n");
	return 0;
}
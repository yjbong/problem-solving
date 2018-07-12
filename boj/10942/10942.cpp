#include <cstdio>
#define MAX_N 2000
int N; // 수열의 크기
int A[MAX_N]; // 수열
int M; // 질문의 개수

int D[MAX_N][MAX_N]; // D[i][j] = A[i~j]가 팰린드롬이면 1, 아니면 0
int main(void) {

	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);

	for (int i = 0; i < N; i++) D[i][i] = 1; // 길이 1인 문자열은 항상 팰린드롬이다.
	for (int i = 0; i < N - 1; i++) D[i][i + 1] = A[i] == A[i + 1] ? 1 : 0; // 길이 2인 문자열에 대한 초기화

	// DP
	for (int j = 2; j < N; j++)
		for (int i = 0; i + j < N; i++)
			D[i][i + j] = D[i + 1][i + j - 1] && A[i] == A[i + j] ? 1 : 0;
	
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int S, E;
		scanf("%d %d", &S, &E);
		S--, E--;
		printf("%d\n", D[S][E]); // 질문에 대한 답을 출력
	}

	return 0;
}
#include <cstdio>
#include <cstdlib>
#define MAXN 2000
#define INF 2100000000

int N; // 음의 개수
int A[MAXN + 1]; // A[i] = i번째 음의 높이

int D[MAXN + 1][MAXN + 1]; // 현재까지 1~i번 음을 불렀고, 마지막 음(i번)을 부르지 않은 사람이 최근에 부른 음이 j번 음인 경우, 두 사람의 힘든 정도의 합의 최소값

int min2(int a, int b) { return a < b ? a : b; }
int diff(int a, int b) { // diff(a, b) = a번 음과 b번 음의 차이값을 리턴 (a 또는 b가 0번인 경우는 무조건 0)
	if (a == 0 || b == 0) return 0;
	else return abs(A[a] - A[b]);
}
int main(void) {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &A[i]);

	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= N; j++) D[i][j] = INF;
	D[0][0] = 0;

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < i; j++) { 
			D[i][j] = min2(D[i][j], D[i - 1][j] + diff(i - 1, i)); // i-1번 음을 부른 사람이 i번 음을 부르는 경우
			if (j == i - 1) {
				// i-1번 음을 부르지 않은 사람이 i번 음을 부르는 경우
				for (int k = 0; k < i - 1; k++) D[i][j] = min2(D[i][j], D[i - 1][k] + diff(k, i));
			}
		}
	}

    // 답 계산 및 출력
	int ans = INF;
	for (int j = 0; j < N; j++)
		ans = min2(ans, D[N][j]);
	printf("%d\n", ans);

	return 0;
}
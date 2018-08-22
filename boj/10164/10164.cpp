#include <cstdio>
#define MAXN 15
#define MAXM 15
int N; // 행의 수
int M; // 열의 수
int K; // 지나야 하는 칸의 번호

// 편의상 행과 열의 번호는 0부터
int D[MAXN][MAXM][2]; // D[i][]][0] = K번 칸을 지나지 않았으면서 시작점에서 i행 j열로 가는 경로의 수
					  // D[i][j][1] = K번 칸을 지났으면서 시작점에서 i행 j열로 가는 경로의 수
int main(void) {
	scanf("%d %d %d", &N, &M, &K);
	int Y, X;
	// 반드시 지나야 하는 칸이 있는 경우
	if (K > 0) {
		// 편의상 칸의 번호가 0부터인 것으로 한다.
		Y = (K - 1) / M;
		X = (K - 1) % M;
	}
	else Y = X = -1;

	D[0][0][0] = 1; // 문제 조건상 K는 시작점이 아님
	// DP
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i == Y && j == X) {
				D[i][j][1] += i > 0 ? D[i - 1][j][0] + D[i - 1][j][1] : 0;
				D[i][j][1] += j > 0 ? D[i][j - 1][0] + D[i][j - 1][1] : 0;
			}
			else {
				D[i][j][0] += i > 0 ? D[i - 1][j][0] : 0;
				D[i][j][0] += j > 0 ? D[i][j - 1][0] : 0;
				D[i][j][1] += i > 0 ? D[i - 1][j][1] : 0;
				D[i][j][1] += j > 0 ? D[i][j - 1][1] : 0;
			}
		}
	}

	// 답 출력
	int ans;
	if (K > 0) ans = D[N - 1][M - 1][1];
	else ans = D[N - 1][M - 1][0];
	printf("%d\n", ans);

	return 0;
}
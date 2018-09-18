#include <cstdio>
#define MAXN 1000
#define MAXM 1000
#define INF 1000000000
int N; // 노트의 적을 사람의 수
int M; // 노트의 가로 칸의 개수
int A[MAXN]; // A[i] = i번째 사람의 이름의 길이

int min2(int a, int b) { return a < b ? a : b; }

// go(idx, col) = idx번부터 N번까지의 사람을 노트에 적어야 하고, 현재 노트의 행에서 처음으로 비어 있는 곳(띄어쓰기 때문에 빈 곳 제외)이
//				  col열일 때, 가능한 벌점의 최소값 (col==M 이라면 현재 줄에 빈 칸이 없는 것임)
int cache[MAXN+1][MAXM+1];

int go(int idx, int col) {
	if (idx >= N) return 0;
	if (cache[idx][col] >= 0) return cache[idx][col];
	int result = INF;
	// case 1: idx번 사람의 이름을 현재 행에 이어서 적음
	if (col > 0) { // 현재 행에 다른 이름이 먼저 쓰여져 있는 경우 --> 먼저 써진 이름 뒤에 한 칸 띄우고 써여 함
		if (col + 1 + A[idx] <= M) result = min2(result, go(idx + 1, col + 1 + A[idx]));
	}
	else result = min2(result, go(idx + 1, A[idx])); // 그렇지 않다면 처음(0열)부터 쓰면 됨

	// case 2: idx번 사람의 이름을 새 줄에 쓰는 경우 --> 현재 줄에 남은 칸 수의 제곱만큼 벌점 추가
	result = min2(result, go(idx + 1, A[idx]) + (M - col)*(M - col));

	return cache[idx][col] = result;
}

int main(void) {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);

	// cache 초기화
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= M; j++) cache[i][j] = -1;

	// 답 계산
	printf("%d\n", go(0, 0));

	return 0;
}
#include <cstdio>
#define MAXN 100
int N; // 원 위에 있는 수의 개수
int A[MAXN]; // A[i] = i번째 수
int P[MAXN]; // P[i] = A[0 ~ i] 중 홀수의 개수

int D[MAXN][MAXN];

int max2(int a, int b) { return a > b ? a : b; }

// countOdds(i, j) = A[i ~ j] 에 있는 홀수의 개수
int countOdds(int i, int j) {
	if (i == 0) return P[j];
	else if (i <= j) return P[j] - P[i - 1];
	else return P[N - 1] - P[i - 1] + P[j];
}
// maxScore(i, j) = A[i]~A[j]가 이미 선택되어 있는 상태일 때, 현재 플레이어가 얻는 최대 점수
int maxScore(int i, int j) {
	if ((j + 1) % N == i) return 0; // 남은 수가 하나도 없는 경우
	if (D[i][j] >= 0) return D[i][j]; // memoization

	// 현재 플레이어가 인접한 왼쪽 숫자(A[i-1])를 선택한 경우
	int left = (i - 1 + N) % N;
	int pickLeft = (A[left] % 2) + (P[N-1]-countOdds(left, j) - maxScore(left, j));
	// 현재 플레이어가 인접한 오른쪽 숫자(A[j+1])를 선택한 경우
	int right = (j + 1) % N;
	int pickRight = (A[right] % 2) + (P[N-1]-countOdds(i, right) - maxScore(i, right));

	// 두 경우 중 값이 큰 경우를 선택
	return (D[i][j] = max2(pickLeft, pickRight));
}

int main(void) {

	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);

	// P 계산
	P[0] = A[0] % 2;
	for (int i = 1; i < N; i++) P[i] = P[i - 1] + (A[i] % 2);
	
	// D 초기화
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) D[i][j] = -1;

	int ans = 0;
	for (int i = 0; i < N; i++) {
		int myScore = (A[i] % 2) + (P[N-1]-countOdds(i, i) - maxScore(i, i)); // 선영이가 처음에 A[i]를 골랐을 때 얻을 수 있는 최대 점수
		if (myScore > P[N-1] - myScore) ans++; // 선영이의 점수가 정인이의 점수보다 높은 경우 답을 update
	}
	printf("%d\n", ans);

	return 0;
}
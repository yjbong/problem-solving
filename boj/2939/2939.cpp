#include <cstdio>
#include <utility>
#define INF 1000000000
#define MAXR 2000
#define MAXC 200
using namespace std;
// pos에서 사용할 때 -> first: 행 번호(0 ~ R-1), second: 열 번호(0 ~ C-1)
typedef pair<int, int> ii;

int R, C; // 도시의 크기 (R*C)
int T[MAXR][MAXC]; // T[i][j] = 도시의 칸 i행 j열을 지나는데 걸리는 시간
int D; // 배달해야 하는 물품(=쿼리)의 수

int SRow[MAXR][2]; // SRow[i][0] = T[0][0] + T[1][0] + ... + T[i][0]
				   // SRow[i][1] = T[0][C-1] + T[1][C-1] + ... + T[i][C-1]

int S[MAXR][MAXC]; // S[i][j] = T[i][0] + T[i][1] + ... + T[i][j]

// dist[i][0][j][0] = (i,0)에서 (j,0)으로 가기 위한 최단 시간
// dist[i][0][j][1] = (i,0)에서 (j,C-1)으로 가기 위한 최단 시간
// dist[i][1][j][0] = (i,C-1)에서 (j,0)으로 가기 위한 최단 시간
// dist[i][1][j][1] = (i,C-1)에서 (j,C-1)으로 가기 위한 최단 시간
int dist[MAXR][2][MAXR][2];

int min2(int a, int b) { return a < b ? a : b; }

void calcDist(void) {
	// 먼저, 동일한 행에서 0열과 C-1열 사이의 최단 시간을 계산
	for (int i = 0; i < R; i++) {

		dist[i][0][i][0] = dist[i][1][i][1] = 0;

		// i행 0열 -> i행 C-1열의 최단 시간 계산
		dist[i][0][i][1] = S[i][C - 1] - S[i][0]; // i행 외의 다른 행을 거치지 않는 경우의 답으로 초기화
		// j행을 경유하는 케이스
		for (int j = 0; j < R; j++) {
			if (i < j) { // j행이 i행보다 아래에 있는 경우
				dist[i][0][i][1] = min2(dist[i][0][i][1], SRow[j][0] - SRow[i][0] + S[j][C - 1] - S[j][0] + SRow[j - 1][1] - (i > 0 ? SRow[i - 1][1] : 0));
			}
			else if (i > j) { // j행이 i행보다 위에 있는 경우
				dist[i][0][i][1] = min2(dist[i][0][i][1], SRow[i - 1][0] - (j > 0 ? SRow[j - 1][0] : 0) + S[j][C - 1] - S[j][0] + SRow[i][1] - SRow[j][1]);
			}
		}

		// i행 C-1열 -> i행 0열의 최단 시간 계산
		dist[i][1][i][0] = S[i][C - 2]; // i행 외의 다른 행을 거치지 않는 경우의 답으로 초기화
		// j행을 경유하는 케이스
		for (int j = 0; j < R; j++) {
			if (i < j) { // j행이 i행보다 아래에 있는 경우
				dist[i][1][i][0] = min2(dist[i][1][i][0], SRow[j][1] - SRow[i][1] + S[j][C - 2] + SRow[j - 1][0] - (i > 0 ? SRow[i - 1][0] : 0));
			}
			else if (i > j) { // j행이 i행보다 위에 있는 경우
				dist[i][1][i][0] = min2(dist[i][1][i][0], SRow[i - 1][1] - (j > 0 ? SRow[j - 1][1] : 0) + S[j][C - 2] + SRow[i][0] - SRow[j][0]);
			}
		}
	}

	// 시작 위치의 행과 도착 위치의 행이 다른 경우
	// 시작 행과 도착 행의 행간 거리가 가까운 순서대로 Dynamic Programming 수행
	for (int diff = 1; diff < R; diff++){

		// 시작 행보다 도착 행이 아래쪽(index가 더 큼)인 경우
		for (int i = 0; i + diff < R; i++) {
			int j = i + diff; // 도착 위치가 있는 행

			// (i,0) -> (j,0)의 최단시간 = 경로 (i,0) -> (i+1,0) -> (j,0) 과 (i,0) -> (i,C-1) -> (i+1,C-1) -> (j,0) 중 최소값 
			dist[i][0][j][0] = min2(T[i + 1][0] + dist[i + 1][0][j][0], dist[i][0][i][1] + T[i + 1][C - 1] + dist[i + 1][1][j][0]);

			// (i,0) -> (j,C-1)의 최단시간 = 경로 (i,0) -> (i+1,0) -> (j,C-1) 과 (i,0) -> (i,C-1) -> (i+1,C-1) -> (j,C-1) 중 최소값
			dist[i][0][j][1] = min2(T[i + 1][0] + dist[i + 1][0][j][1], dist[i][0][i][1] + T[i + 1][C - 1] + dist[i + 1][1][j][1]);

			// (i,C-1) -> (j,0)의 최단시간 = 경로 (i,C-1) -> (i+1,C-1) -> (j,0) 과 (i,C-1) -> (i,0) -> (i+1,0) -> (j,0) 중 최소값
			dist[i][1][j][0] = min2(T[i + 1][C - 1] + dist[i + 1][1][j][0], dist[i][1][i][0] + T[i + 1][0] + dist[i + 1][0][j][0]);

			// (i,C-1) -> (j,C-1)의 최단시간 = 경로 (i,C-1) -> (i+1,C-1) -> (j,C-1) 과 (i,C-1) -> (i,0) -> (i+1,0) -> (j,C-1) 중 최소값
			dist[i][1][j][1] = min2(T[i + 1][C - 1] + dist[i + 1][1][j][1], dist[i][1][i][0] + T[i + 1][0] + dist[i + 1][0][j][1]);
		}

		// 시작 행보다 도착 행이 위쪽(index가 더 작음)인 경우
		for (int i = diff; i < R; i++) {
			int j = i - diff; // 도착 위치가 있는 행

			// (i,0) -> (j,0)의 최단시간 = 경로 (i,0) -> (i-1,0) -> (j,0) 과 (i,0) -> (i,C-1) -> (i-1,C-1) -> (j,0) 중 최소값
			dist[i][0][j][0] = min2(T[i - 1][0] + dist[i - 1][0][j][0], dist[i][0][i][1] + T[i - 1][C - 1] + dist[i - 1][1][j][0]);

			// (i,0) -> (j,C-1)의 최단시간 = 경로 (i,0) -> (i-1,0) -> (j,C-1) 과 (i,0) -> (i,C-1) -> (i-1,C-1) -> (j,C-1) 중 최소값
			dist[i][0][j][1] = min2(T[i - 1][0] + dist[i - 1][0][j][1], dist[i][0][i][1] + T[i - 1][C - 1] + dist[i - 1][1][j][1]);

			// (i,C-1) -> (j,0)의 최단시간 = 경로 (i,C-1) -> (i-1,C-1) -> (j,0) 과 (i,C-1) -> (i,0) -> (i-1,0) -> (j,0) 중 최소값
			dist[i][1][j][0] = min2(T[i - 1][C - 1] + dist[i - 1][1][j][0], dist[i][1][i][0] + T[i - 1][0] + dist[i - 1][0][j][0]);

			// (i,C-1) -> (j,C-1)의 최단시간 = 경로 (i,C-1) -> (i-1,C-1) -> (j,C-1) 과 (i,C-1) -> (i,0) -> (i-1,0) -> (j,C-1) 중 최소값
			dist[i][1][j][1] = min2(T[i - 1][C - 1] + dist[i - 1][1][j][1], dist[i][1][i][0] + T[i - 1][0] + dist[i - 1][0][j][1]);
		}
	}
}

// query(from, to) : from에서 to로 가는 최단 시간 계산
int query(ii from, ii to) {
	int fromR = from.first, fromC = from.second; // 출발지 좌표 = (fromR, fromC)
	int toR = to.first, toC = to.second; // 도착지 좌표 = (toR, toC)

	// 열이 1개 뿐인 경우
	if (C == 1) {
		if (fromR < toR) return SRow[toR][0] - SRow[fromR][0];
		else if (fromR == toR) return 0;
		else return SRow[fromR - 1][0] - (toR > 0 ? SRow[toR - 1][0] : 0);
	}
	// 열이 2개 이상 있는 경우
	else {
		int result = INF, caseResult;

		// Case 1: (fromR, fromC) -> (fromR, 0) -> (toR, 0) -> (toR, toC)
		caseResult = (fromC > 0 ? S[fromR][fromC - 1] : 0);// (fromR, fromC) -> (fromR, 0)
		caseResult += dist[fromR][0][toR][0]; // (fromR, 0) -> (toR, 0)
		caseResult += S[toR][toC] - S[toR][0]; // (toR, 0) -> (toR, toC)
		if (result > caseResult) result = caseResult;

		// Case 2: (fromR, fromC) -> (fromR, 0) -> (toR, C-1) -> (toR, toC)
		caseResult = (fromC > 0 ? S[fromR][fromC - 1] : 0); // (fromR, fromC) -> (fromR, 0)
		caseResult += dist[fromR][0][toR][1]; // (fromR, 0) -> (toR, C-1)
		caseResult += S[toR][C - 2] - (toC > 0 ? S[toR][toC - 1] : 0); // (toR, C-1) -> (toR, toC)
		if (result > caseResult) result = caseResult;

		// Case 3: (fromR, fromC) -> (fromR, C-1) -> (toR, 0) -> (toR, toC)
		caseResult = S[fromR][C-1] - S[fromR][fromC]; // (fromR, fromC) -> (fromR, C-1)
		caseResult += dist[fromR][1][toR][0]; // (fromR, C-1) -> (toR, 0)
		caseResult += S[toR][toC] - S[toR][0]; // (toR, 0) -> (toR, toC)
		if (result > caseResult) result = caseResult;

		// Case 4: (fromR, fromC) -> (fromR, C-1) -> (toR, C-1) -> (toR, toC)
		caseResult = S[fromR][C - 1] - S[fromR][fromC]; // (fromR, fromC) -> (fromR, C-1)
		caseResult += dist[fromR][1][toR][1]; // (fromR, C-1) -> (toR, C-1)
		caseResult += S[toR][C - 2] - (toC > 0 ? S[toR][toC - 1] : 0); // (toR, C-1) -> (toR, toC)
		if (result > caseResult) result = caseResult;

		// Case 5: (fromR, fromC) -> (toR, toC), 단 fromR==toR 일 때만
		if (fromR == toR) {
			if (fromC < toC) caseResult = S[fromR][toC] - S[fromR][fromC];
			else if (fromC == toC) caseResult = 0;
			else caseResult = S[fromR][fromC - 1] - (toC > 0 ? S[fromR][toC - 1] : 0);
			if (result > caseResult) result = caseResult;
		}

		return result;
	}
}

int main(void) {
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			scanf("%d", &T[i][j]);

	// SRow 계산
	SRow[0][0] = T[0][0];
	for (int i = 1; i < R; i++) SRow[i][0] = SRow[i - 1][0] + T[i][0];
	if (C > 1) {
		SRow[0][1] = T[0][C - 1];
		for (int i = 1; i < R; i++) SRow[i][1] = SRow[i - 1][1] + T[i][C - 1];

		// S 계산
		for (int i = 0; i < R; i++) {
			S[i][0] = T[i][0];
			for (int j = 1; j < C; j++) S[i][j] = S[i][j - 1] + T[i][j];
		}

		// 0열과 C-1열에 있는 각 칸들의 모든 쌍에 대해 최단 시간 계산 
		calcDist();
	}

	// 쿼리 입력
	scanf("%d", &D);
	ii from, to;
	from.first = 0, from.second = 0; // 빠름택배의 위치 (행과 열 번호는 0부터 시작하는 것으로 생각할 것이므로 (1,1)이 아니라 (0,0))

	long long ans = T[0][0]; // 처음에 빠름택배가 있는 칸을 무조건 지나게 된다.
	// 각 쿼리를 처리
	for (int i = 0; i < D; i++) {
		scanf("%d %d", &to.first, &to.second);
		to.first--, to.second--; // 행과 열 번호는 0부터 시작하는 것으로 생각한다.
		ans += query(from, to); // 현재 위치에서 배달 위치까지 가는 최단 시간을 더함
		from.first = to.first, from.second = to.second; // 이번 iteration의 배달 위치가 다음 iteration의 현재 위치임
	}

	// 답 출력
	printf("%lld\n", ans);
	return 0;
}
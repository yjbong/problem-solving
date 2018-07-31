#include <cstdio>
#define MAXN 300000 // 최대 난쟁이의 수
#define MAXC 10000 // 최대 모자 색상의 수
#define MAXM 10000 // 최대 사진(쿼리)의 수
#define THRESHOLD 7500 // 쿼리의 범위 크기가 THRESHOLD 이하라면 Naive search를 한다.

int N; // 난쟁이의 수
int C; // 모자 색상의 수
int color[MAXN]; // color[i] = i번 난쟁이가 쓰고 있는 모자의 색상
int M; // 사진의 수

int curCount[MAXC + 1]; // curCount[i] = 현재 쿼리에서 i번 색상이 등장한 회수
int totalCount[MAXC + 1]; // totalCount[i] = i번 색상의 전체 등장 회수

// 구간의 크기가 THRESHOLD 이상일 때만 Prefix sum을 이용하여 쿼리를 O(1)에 처리할 것이다.
// 이 때 Prefix sum을 가져야 하는 색상의 수는 많아야 (N / (THRESHOLD / 2 + 1)) 개이다.
// 왜냐하면 구간의 크기가 THRESHOLD 인 경우, 특정 색상이 과반수가 되기 위해서는 (THRESHOLD / 2 + 1) 명의 난쟁이가 그 색상이어야 한다.
// 그런데 전체 색상 중 등장 회수가 (THRESHOLD / 2 + 1) 개 이상인 색상은 많아야 (N / (THRESHOLD / 2 + 1)) 개이기 때문에 그만큼만 있으면 된다.

int idxToColor[MAXN / (THRESHOLD / 2 + 1)]; // idxToColor[i] = prefixSm 번호가 i인 색상의 번호
int prefixSum[MAXN / (THRESHOLD / 2 + 1)][MAXN]; // prefixSum[i][j] = 0 ~ j번 난쟁이들에 대해, prefixSum 번호가 i인 색상(idxToColor[i])이 등장한 회수
int numPrefixSums;

int main(void) {
	scanf("%d %d", &N, &C);
	for (int i = 0; i < N; i++) scanf("%d", &color[i]);

	// 각 색상의 전체 등장 회수 totalCount 계산
	for (int i = 0; i < N; i++) totalCount[color[i]]++;

	// 등장 회수가 THRESHOLD / 2 + 1 이상인 색상에 대해서만 prefixSum을 만든다.
	numPrefixSums = 0;
	for (int i = 1; i <= C; i++) {
		if (totalCount[i] >= THRESHOLD / 2 + 1) {
			idxToColor[numPrefixSums++] = i; // prefixSum 목록에 i번 색상을 추가
		}
	}

	// prefixSum 계산
	for (int i = 0; i < numPrefixSums; i++) {
		for (int j = 0; j < N; j++) {
			if (idxToColor[i] == color[j]) { // prefixSum[i]의 색상이 현재 난쟁이의 색상과 같은 경우
				if (j == 0) prefixSum[i][j] = 1;
				else prefixSum[i][j] = prefixSum[i][j - 1] + 1;
			}
			else { // prefixSum[i]의 색상이 현재 난쟁이의 색상과 다른 경우
				if (j == 0) prefixSum[i][j] = 0;
				else prefixSum[i][j] = prefixSum[i][j - 1];
			}
		}
	}

	// 각 쿼리에 대한 처리
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int A, B;
		scanf("%d %d", &A, &B);
		A--, B--; // 코드 상에서 난쟁이의 번호는 0부터 시작한다고 본다. (입력은 1부터 시작한다고 생각하여 들어옴)

		int overHalfColor = -1; // 현재 쿼리에서 과반인 색상의 수

		// 쿼리 구간 크기가 THRESHOLD 이하인 경우 Naive search
		if (B - A + 1 <= THRESHOLD) {

			// curCount 초기화 및 계산
			for (int j = 1; j <= C; j++) curCount[j] = 0;
			for (int j = A; j <= B; j++) curCount[color[j]]++;

			// 과반수인 색상을 찾음
			for (int j = 1; j <= C; j++) {
				if (curCount[j] > (B - A + 1) / 2) {
					overHalfColor = j;
					break;
				}
			}
		}

		// 쿼리 구간 크기가 THRESHOLD보다 큰 경우 Prefix sum 이용
		else {
			for (int j = 0; j < numPrefixSums; j++) {
				int count = prefixSum[j][B];
				if (A > 0) count -= prefixSum[j][A - 1];
				if (count > (B - A + 1) / 2) {
					overHalfColor = idxToColor[j];
					break;
				}
			}
		}

		// 쿼리 결과 출력
		if (overHalfColor < 0) printf("no\n");
		else printf("yes %d\n", overHalfColor);
	}
}
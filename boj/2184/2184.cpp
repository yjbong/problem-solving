#include <cstdio>
#include <algorithm>
#define MAXN 1000
#define INF 2000000000
int min2(int a, int b) { return a < b ? a : b; }
int N; // 김치를 배달할 곳의 위치
int L; // 김치 공장의 위치
int pos[MAXN + 1]; // x좌표들 (김치 배달 위치 + 김치 공장 위치)

// cache[i][j][0] = pos[i~j] 구간에 김치를 모두 배달했고 현재 위치가 pos[i] 일 때, 앞으로 배달할 김치들이 쉬는 정도의 합의 최소값
// cache[i][j][1] = pos[i~j] 구간에 김치를 모두 배달했고 현재 위치가 pos[j] 일 때, 앞으로 배달할 김치들이 쉬는 정도의 합의 최소값
int cache[MAXN + 1][MAXN + 1][2]; 

int go(int left, int right, int atRight) {
	if (left == 0 && right == N - 1) return 0; // 배달이 모두 끝남
	if (cache[left][right][atRight] >= 0) return cache[left][right][atRight]; // memoization

	int result = INF;
	// 현재 위치에서 pos[left-1] 로 김치 배달
	if (left > 0) result = min2(result, go(left - 1, right, 0) + (atRight ? pos[right] - pos[left - 1] : pos[left] - pos[left - 1]) * (left + N - 1 - right));
	// 현재 위치에서 pos[right+1] 로 김치 배달
	if (right < N - 1) result = min2(result, go(left, right + 1, 1) + (atRight ? pos[right + 1] - pos[right] : pos[right + 1] - pos[left]) * (left + N - 1 - right));

	return (cache[left][right][atRight] = result);
}

int main(void) {
	scanf("%d %d", &N, &L);
	for (int i = 0; i < N; i++) scanf("%d", &pos[i]);
	pos[N++] = L; // 김치 공장 위치를 추가
	std::sort(pos, pos + N);

	// 초기화
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cache[i][j][0] = cache[i][j][1] = -1;
	
	// 답 출력
	int factoryIdx;
	for (int i = 0; i < N; i++)
		if (pos[i] == L) { factoryIdx = i; break; }
	printf("%d\n", go(factoryIdx, factoryIdx, 0));
	return 0;
}
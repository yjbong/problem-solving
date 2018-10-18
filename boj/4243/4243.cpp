#include <cstdio>
#define MAXN 100
#define INF 1000000000000000000ll
typedef long long ll;
int T; // 테스트 케이스
int N; // 상점의 수
int a; // 시작점의 위치
ll t[MAXN - 1]; // t[i] = i번 상점과 i+1번 상점의 거리
ll s[MAXN - 1]; // s[i] = t[0] + t[1] + ... + t[i]

ll min2(ll a, ll b) { return a < b ? a : b; }

// dist(from, to) = from번째 상점에서 to번째 상점으로 갈 때의 이동 거리
ll dist(int from, int to) {
	ll result = 0;
	if (from < to) {
		if (to > 0) result += s[to - 1];
		if (from > 0) result -= s[from - 1];
	}
	else if (from > to) {
		if (from > 0) result += s[from - 1];
		if (to > 0) result -= s[to - 1];
	}
	return result;
}

// go(left, right, 0) = 현재까지 순찰한 구간이 left ~ right 이고, 현재 위치는 left번 상점일 때, 남은 상점들을 순찰하는데 드는 대기시간의 합의 최소값
// go(left, right, 1) = 현재까지 순찰한 구간이 left ~ right 이고, 현재 위치는 right번 상점일 때, 남은 상점들을 순찰하는데 드는 대기시간의 합의 최소값
ll cache[MAXN][MAXN][2];
ll go(int left, int right, int atRight) {

	if (cache[left][right][atRight] >= 0) return cache[left][right][atRight]; // memoization

	int remain = N - (right - left + 1);
	if (remain == 0) return 0;

	ll result = INF;
	// case 1: 현재 위치에서 (left-1)번째 상점으로 이동
	if (left - 1 >= 0) result = min2(result, go(left - 1, right, 0) + remain * (atRight ? dist(right, left - 1) : dist(left, left - 1)));

	// case 2: 현재 위치에서 (right+1)번째 상점으로 이동
	if (right + 1 < N) result = min2(result, go(left, right + 1, 1) + remain * (atRight ? dist(right, right + 1) : dist(left, right + 1)));

	return cache[left][right][atRight] = result; // memoization
}

int main(void) {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		scanf("%d", &a); a--; // 1번이 아니라 0번 상점부터 있다고 생각
		for (int i = 0; i < N - 1; i++) scanf("%lld", &t[i]);
		s[0] = t[0];
		for (int i = 1; i < N - 1; i++) s[i] = s[i - 1] + t[i];

		// DP
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cache[i][j][0] = cache[i][j][1] = -1;
		printf("%lld\n", go(a, a, 0));
	}
	return 0;
}
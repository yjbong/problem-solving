#include <cstdio>
#define MAXN 100000
#define INF 1000000000000000ll
typedef long long ll;
int N; // 보석의 개수
int M; // 연속으로 주워야 하는 보석의 최소 개수
ll A[MAXN]; // A[i] = i번 보석의 가치 * 1000

// for checking
ll B[MAXN]; // B[i] = A[i] - 현재의 목표 average값
ll S[MAXN]; // S[i] = B[0] + ... + B[i]

ll seg[1 << 18]; // segment tree
int base;
ll min2(ll a, ll b) { return a < b ? a : b; }
ll query(int left, int right) { // 구간 S[left ~ right] 에서의 최소값 리턴 

	ll result = INF;

	left += base;  right += base;
	while (left < right) {
		if (left % 2 == 0) left /= 2;
		else {
			result = min2(result, seg[left]);
			left = (left + 1) / 2;
		}
		if (right % 2 == 1) right /= 2;
		else {
			result = min2(result, seg[right]);
			right = (right - 1) / 2;
		}
	}
	if (left == right) result = min2(result, seg[left]);
	return result;
}
void update(int idx, ll value) { // S[idx] 에 value 대입
	idx += base;
	if (seg[idx] > value) {
		seg[idx] = value;
		while (idx / 2 >= 1) {
			idx /= 2;
			seg[idx] = min2(seg[idx * 2], seg[idx * 2 + 1]);
		}
	}
}

// 길이가 M 이상이면서 평균값이 average 이상인 subsequence가 존재하면 true
bool checking(ll average, int M) {

	for (int i = 0; i < N; i++) B[i] = A[i] - average;
	S[0] = B[0];
	for (int i = 1; i < N; i++) S[i] = S[i - 1] + B[i];

	// segment tree 초기화
	for (int i = base; i < base * 2; i++) seg[i] = INF;
	for (int i = base - 1; i >= 1; i--) seg[i] = min2(seg[i * 2], seg[i * 2 + 1]);

	for (int i = 0; i < N; i++) {
		update(i, S[i]);
		if (i >= M - 1) {
			if (S[i] >= 0) return true;
			else if (i > M - 1) {
				if (S[i] - query(0, i - M) >= 0) return true;
			}
		}
	}
	return false;
}

int main(void) {

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &A[i]);
		A[i] *= 1000;
	}

	// init base (for segment tree)
	base = 1;
	while (base < N) base *= 2;

	// Parametric search (for average)
	ll ans = 0;
	ll left = 0, right = 2000 * 1000;
	while (left <= right) {
		ll mid = (left + right) / 2;
		if (checking(mid, M)) {
			if (ans < mid) ans = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}
	printf("%lld\n", ans);

	return 0;
}
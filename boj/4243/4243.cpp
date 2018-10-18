#include <cstdio>
#define MAXN 100
#define INF 1000000000000000000ll
typedef long long ll;
int T; // �׽�Ʈ ���̽�
int N; // ������ ��
int a; // �������� ��ġ
ll t[MAXN - 1]; // t[i] = i�� ������ i+1�� ������ �Ÿ�
ll s[MAXN - 1]; // s[i] = t[0] + t[1] + ... + t[i]

ll min2(ll a, ll b) { return a < b ? a : b; }

// dist(from, to) = from��° �������� to��° �������� �� ���� �̵� �Ÿ�
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

// go(left, right, 0) = ������� ������ ������ left ~ right �̰�, ���� ��ġ�� left�� ������ ��, ���� �������� �����ϴµ� ��� ���ð��� ���� �ּҰ�
// go(left, right, 1) = ������� ������ ������ left ~ right �̰�, ���� ��ġ�� right�� ������ ��, ���� �������� �����ϴµ� ��� ���ð��� ���� �ּҰ�
ll cache[MAXN][MAXN][2];
ll go(int left, int right, int atRight) {

	if (cache[left][right][atRight] >= 0) return cache[left][right][atRight]; // memoization

	int remain = N - (right - left + 1);
	if (remain == 0) return 0;

	ll result = INF;
	// case 1: ���� ��ġ���� (left-1)��° �������� �̵�
	if (left - 1 >= 0) result = min2(result, go(left - 1, right, 0) + remain * (atRight ? dist(right, left - 1) : dist(left, left - 1)));

	// case 2: ���� ��ġ���� (right+1)��° �������� �̵�
	if (right + 1 < N) result = min2(result, go(left, right + 1, 1) + remain * (atRight ? dist(right, right + 1) : dist(left, right + 1)));

	return cache[left][right][atRight] = result; // memoization
}

int main(void) {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		scanf("%d", &a); a--; // 1���� �ƴ϶� 0�� �������� �ִٰ� ����
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
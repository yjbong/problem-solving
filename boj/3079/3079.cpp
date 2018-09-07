#include <cstdio>
#define MAXN 100000ll
#define MAXM 1000000000ll
#define MAXT 1000000000ll
typedef long long ll;
ll N; // �Ա��ɻ���� ��
ll M; // ����� ��
ll T[MAXN]; // T[i] = i�� �ɻ�뿡�� �ɻ縦 �ϴµ� �ɸ��� �ð�

// M���� ������� time ���� ��� �Ա��ɻ縦 ���� �� �ִٸ� true
bool finishable(ll time) {
	ll done = 0;
	for (int i = 0; i < N; i++) done += time / T[i];
	return (done >= M);
}

int main(void) {
	
	scanf("%lld %lld", &N, &M);
	for (int i = 0; i < N; i++) scanf("%lld", &T[i]);

	ll ans = MAXM * MAXT;
	// �̺�Ž��
	ll left = 1, right = MAXM * MAXT;
	while (left <= right) {
		ll mid = (left + right) / 2;
		if (finishable(mid)) {
			if (ans > mid) ans = mid;
			right = mid - 1;
		}
		else left = mid + 1;
	}
	printf("%lld\n", ans);

	return 0;
}
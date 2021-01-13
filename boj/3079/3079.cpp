#include <cstdio>
#define MAXN 100000ll
#define MAXM 1000000000ll
#define MAXT 1000000000ll
typedef long long ll;
ll N; // 입국심사대의 수
ll M; // 사람의 수
ll T[MAXN]; // T[i] = i번 심사대에서 심사를 하는데 걸리는 시간

// M명의 사람들이 time 내에 모두 입국심사를 끝낼 수 있다면 true
bool finishable(ll time) {
	ll done = 0;
	for (int i = 0; i < N; i++){
        done += time / T[i];
        if(done >= M) return true;
    }
	return false;
}

int main(void) {
	
	scanf("%lld %lld", &N, &M);
	for (int i = 0; i < N; i++) scanf("%lld", &T[i]);

	ll ans = MAXM * MAXT;
	// 이분탐색
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
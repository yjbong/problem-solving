#include <cstdio>
typedef long long ll;

ll p[17]; // p[i] = 10^i
ll s[10]; // s[i]=0+1+2+...+i

// digitSum_naive(n) = [0,n]의 자리 합
ll digitSum_naive(ll n) {
	ll ret = 0;
	for (ll i = 0; i <= n; i++) {
		ll t = i;
		while (t > 0) {
			ret += t % 10;
			t /= 10;
		}
	}
	return ret;
}

// digitSum(n) = [0,n]의 자리 합
ll digitSum(ll n) {

	ll ret = 0;

	// n의 자릿수를 구한다
	ll t = n;
	int dgts = 0;
	while (t > 0) {
		dgts++;
		t /= 10;
	}

	for (int i = 0; i < dgts; i++) {
		// i번 iteration은 10^i 자리의 자리 합을 구한다.
		ret += ((n + 1) / p[i + 1])*s[9] * p[i];
		ll rem = (n + 1) % p[i + 1];
		if (rem / p[i] > 0) ret += s[rem / p[i] - 1] * p[i];
		ret += (rem / p[i])*(rem%p[i]);
	}

	return ret;
}

int main(void) {

	p[0] = 1;
	for (int i = 1; i <= 16; i++) p[i] = p[i - 1] * 10;
	s[0] = 0;
	for (int i = 1; i <= 9; i++) s[i] = s[i - 1] + i;
	
	int T;
	scanf("%d", &T);
	while (T--) {
		ll a, b, ans;
		scanf("%lld %lld", &a, &b);
		if (a > 0) ans = digitSum(b) - digitSum(a - 1);
		else ans = digitSum(b);
		printf("%lld\n", ans);
	}
	return 0;
}

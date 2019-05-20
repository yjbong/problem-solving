#include <cstdio>
#include <cmath>

#define KEEPING_DIGITS 12
typedef long long ll;
ll N;
ll p[KEEPING_DIGITS+1]; // p[i] = 10의 i승
ll min2(ll a, ll b) { return a < b ? a : b; }
// a! 의 자릿수
ll factoDigits(ll a) {
	if (a < 0) return 0;
	if (a <= 1) return 1;

	double digits = 0;
	for (ll i = 2; i <= a; i++)
		digits += log10(i);

	return floor(digits) + 1;
}
// a! 의 trailing zeros
ll factoTrailingZeros(ll a) {
	ll twos = 0;
	ll fives = 0;
	ll tmp = a;
	while (tmp % 2 == 0) {
		twos += tmp / 2;
		tmp /= 2;
	}
	tmp = a;
	while (tmp % 5 == 0) {
		fives += tmp / 5;
		tmp /= 5;
	}
	return min2(twos, fives);
}

int main(void) {

	p[0] = 1ll;
	for (int i = 1; i <= KEEPING_DIGITS; i++) p[i] = p[i - 1] * 10ll;

	scanf("%lld", &N);
	bool leadingZeros = false;
	ll ans = 1ll;
	for (ll i = 1; i <= N; i++) {
		ll tmp = i;
		while (tmp % 10ll == 0) tmp /= 10ll;
		ans = ans * tmp;
		while (ans % 10ll == 0) ans /= 10ll;
		ans %= p[KEEPING_DIGITS];
	}

	if (factoDigits(N) - factoTrailingZeros(N) > 5) printf("%05lld\n", ans%p[5]);
	else printf("%lld\n", ans%p[5]);
	return 0;
}
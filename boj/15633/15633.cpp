#include <cstdio>
#include <vector>
#define SQRT_MAXN 100
using namespace std;
typedef long long ll;
bool isNotPrime[SQRT_MAXN+1];
vector <ll> primes;
ll sumOfDivisor(ll n) {

	// 에라토스테네스의 체
	isNotPrime[0] = isNotPrime[1] = true;
	for (ll i = 2; i <= SQRT_MAXN; i++) {
		if (!isNotPrime[i]) {
			primes.push_back(i);
			for (ll j = i * 2; j <= SQRT_MAXN; j += i)  isNotPrime[j] = true;
		}
	}

	// 약수의 합 구하기
	ll ans = 1;
	for (int i = 0; i < primes.size(); i++) {
		ll cur = 1;
		while (n % primes[i] == 0) {
			cur *= primes[i];
			cur += 1;
			n /= primes[i];
		}
		ans *= cur;
	}

	if (n > 1) ans *= n + 1;
	return ans;
}

int main(void) {

	ll n;
	scanf("%lld", &n);
	ll ans = sumOfDivisor(n);
	printf("%lld\n", ans * 5 - 24);
	return 0;
}
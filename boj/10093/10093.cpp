#include <cstdio>
typedef long long ll;
ll max2(ll a, ll b) {
	return a > b ? a : b;
}
int main(void) {
	ll A, B, tmp;
	scanf("%lld %lld", &A, &B);
	if (A > B) { tmp = A; A = B; B = tmp; }
	printf("%lld\n", max2(B-A-1,0));
	for (ll i = A + 1; i <= B - 1; i++) printf("%lld ", i);
	printf("\n");
	return 0;
}
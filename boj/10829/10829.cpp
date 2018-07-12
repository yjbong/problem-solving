#include <cstdio>
#include <vector>
long long N;
std::vector <int> bits;
int main(void) {
	scanf("%lld", &N);
	while (N > 0) {
		bits.push_back(N & 1);
		N >>= 1;
	}
	for (int i = bits.size() - 1; i >= 0; i--) printf("%d", bits[i]);
	return 0;
}
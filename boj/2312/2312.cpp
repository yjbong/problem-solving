#include <cstdio>
#include <cmath>
#include <vector>
#define SQRT_MAXN 316 // = floor(sqrt(100000))
using namespace std;
int T; // 테스트 케이스
int N;
bool isNotPrime[SQRT_MAXN+1];
vector <int> primes;
int main(void) {
	isNotPrime[0] = isNotPrime[1] = true;
	for (int i = 2; i <= SQRT_MAXN; i++) {
		if (isNotPrime[i] == false) {
			primes.push_back(i);
			for (int j = i * 2; j <= SQRT_MAXN; j += i) isNotPrime[j] = true;
		}
	}
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		int curPrimeIdx = 0;
		while (N > 1) {
			if (curPrimeIdx == primes.size() && N > 1){ printf("%d %d\n", N, 1); break; }
			int curPow = 0;
			while (N%primes[curPrimeIdx] == 0) { N /= primes[curPrimeIdx]; curPow++; }
			if (curPow > 0) printf("%d %d\n", primes[curPrimeIdx], curPow);
			curPrimeIdx++;
		}
	}
	return 0;
}
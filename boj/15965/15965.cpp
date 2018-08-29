#include <cstdio>
#include <vector>
using namespace std;
bool isNotPrime[7500000];
vector <int> prime;
int main(void) {
	isNotPrime[0] = isNotPrime[1] = true;
	for (int i = 2; i < 7500000; i++)
		if (!isNotPrime[i]) for (int j = i * 2; j < 7500000; j += i) isNotPrime[j] = true;
	for (int i = 0; i < 7500000; i++) if (!isNotPrime[i]) prime.push_back(i);

	int K;
	scanf("%d", &K);
	printf("%d\n", prime[K - 1]);
	
	return 0;
}
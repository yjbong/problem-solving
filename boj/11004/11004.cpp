#include <cstdio>
#include <algorithm>

using namespace std;
int N; // 수열의 크기
int A[5000000]; // 수열
int K;
int main(void) {

	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);

	nth_element(A, A + K-1, A + N);
	printf("%d\n", A[K-1]);

	return 0;
}
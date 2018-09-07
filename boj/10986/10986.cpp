#include <cstdio>
#define MAXN 1000000
#define MAXM 1000

int N; // 수열의 길이
int M; // modular num
int A[MAXN]; // 수열
int S[MAXM]; // S[i] = 현재까지 구한 Prefix sum 중 나머지가 i인 것의 개수

int main(void) {

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);

	int pSum = 0;
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		pSum = (pSum + A[i]) % M;
		if (pSum == 0) ans++; // A[0 ~ i] 의 구간합이 M으로 나누어 떨어짐
		ans += S[pSum]; // 0 < j < i 인 j에 대하여 A[j ~ i] 의 구간합이 M으로 떨어지는 경우들을 더해줌
		S[pSum]++;
	}
	// 답 출력
	printf("%lld\n", ans);
	return 0;
}
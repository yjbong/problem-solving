#include <cstdio>
#include <queue>
#define MAXN 100000
using namespace std;
int N; // 보석의 개수
int M; // 보석을 주울 경우, 연속으로 주워야 하는 보석의 최소 개수i
int A[MAXN]; // A[i] = i번 보석의 가치
int S[MAXN]; // S[i] = A[0] + A[1] + ... + A[i]
int max2(int a, int b) { return a > b ? a : b; }

int main(void) {

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);

	// S 계산
	S[0] = A[0];
	for (int i = 1; i < N; i++) S[i] = S[i - 1] + A[i];

	// 구간 크기 M 이상인 최대 가치합 구간 계산
	priority_queue <int> pq; // j<=i-M 인 모든 S[j]들 중 최소값을 O(lgN)에 구하기 위해 Heap 사용
	int ans = 0; // 보석을 전혀 줍지 않는 경우 답은 0
	for (int i = 0; i < N; i++) {
		if (i >= M) pq.push(-S[i - M]); // 현재 idx에서 M 이상 앞에있는 Prefix sum만 pq에 넣음 (minheap처럼 쓰기 위해 음수 기호를 붙여 넣음)
		if (i >= M - 1) ans = max2(ans, S[i]); // 0번부터 i번 보석까지 줍는 경우 (구간 크기는 M 이상)
		if(!pq.empty()) ans = max2(ans, S[i] - (-pq.top())); // j(!=0)번부터 i번 보석까지 줍는 경우 (구간 크기는 M 이상)
	}
	printf("%d\n", ans);
	return 0;
}
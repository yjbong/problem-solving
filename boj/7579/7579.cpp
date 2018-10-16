#include <cstdio>
#define MAXN 100
#define MAXC 100
int N; // 활성화된 App의 수
int M; // 필요한 메모리 크기(바이트)
int m[MAXN+1]; // m[i] = i번 App이 사용 중인 메모리 크기(바이트)
int c[MAXN+1]; // c[i] = i번 App을 비활성화했을 때의 비용

int max2(int a, int b) { return a > b ? a : b; }

// 이 문제는 knapsack이라 생각하고 푼다.
// 현재 활성화된 App의 수 -> item의 수
// 어떤 App을 비활성화 했을 때의 비용 -> 해당 item의 무게
// 어떤 App을 비활성화 했을 때 확보하는 메모리 크기 -> 해당 item의 가치
// 허용하려는 App의 총 비활성화 비용 -> 배낭의 capacity

int d[MAXN + 1][MAXN*MAXC + 1]; // d[i][j] = 0~i번 item이 있을 때, 배낭의 용량이 j일 때 얻을 수 있는 최대 가치의 합
								//			(= 0~i번 App에 대해, 발생하는 App의 총 비활성화 비용을 최대 j로 제한할 때 확보할 수 있는 최대 메모리 크기)

int main(void) {

	// 입력
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) scanf("%d", &m[i]);
	int csum = 0;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &c[i]);
		csum += c[i];
	}

	// 0-1 knapsack
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= csum; j++) {
			d[i][j] = d[i - 1][j]; // i번 item을 선택하지 않은 경우 (= i번 App을 비활성화하지 않는 경우)
			if (j >= c[i]) d[i][j] = max2(d[i][j], d[i - 1][j - c[i]] + m[i]); // i번 item을 선택하는 경우 (= i번 App을 비활성화하는 경우)
		}
	}
	
	// 답 출력
	int ans = -1;
	for (int j = 0; j <= csum; j++) {
		if (d[N][j] >= M) {
			ans = j; // j = M 이상의 메모리를 확보할 수 있는 최소의 비활성화 비용 제한값 
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}
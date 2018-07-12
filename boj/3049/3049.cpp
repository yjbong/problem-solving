#include <cstdio>
int N;
int main(void) {
	scanf("%d", &N); // N각형
	// N각형의 꼭지점 중 4개를 골라 사각형을 만든다고 생각한다. (그 사각형의 두 대각선이 교차)
	int ans = 0;
	if (N >= 4) ans = N * (N - 1)*(N - 2)*(N - 3) / 4 / 3 / 2 / 1;
	printf("%d\n", ans);
	return 0;
}
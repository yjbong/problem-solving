#include <cstdio>
int A, B, V;
int main(void) {
	scanf("%d %d %d", &A, &B, &V);
	// 마지막날 달팽이는 V-A 이상의 높이에 있어야 함
	// 답 = V-A 이상 높이까지 걸리는 날짜+1
	int ans = (V - A) / (A - B) + (((V - A) % (A - B)) ? 1 : 0) + 1;
	printf("%d\n", ans);
	return 0;
}
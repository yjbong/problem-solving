#include <cstdio>
#define MAXN 1000
int N;
int D[MAXN+1]; // D[i] = 2*i 직사각형을 2x1과 2x2 타일로 채우는 방법의 수
int main(void) {
	scanf("%d", &N);
	D[0] = 1; D[1] = 1;
	for (int i = 2; i <= N; i++) D[i] = (D[i - 1] + D[i - 2] * 2) % 10007;
	printf("%d\n", D[N]);
	return 0;
}
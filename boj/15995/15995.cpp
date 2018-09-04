#include <cstdio>
int a, m;
int main(void) {

	scanf("%d %d", &a, &m);
	// a와 m이 서로소일 때 ax = 1 (mod m)을 만족하는 x는 반드시 존재함
	// 그런데 ax mod m = (a mod m * x mod m) mod m 이므로, 고려할 x의 범위는 0 ~ m-1 임.
	// 이 문제에서는 x가 자연수라는 조건이 있으므로 1 ~ m 의 범위를 보면 됨
	for (int x = 1; x <= m; x++) {
		if ((a*x) % m == 1) {
			printf("%d\n", x);
			break;
		}
	}
	return 0;
}
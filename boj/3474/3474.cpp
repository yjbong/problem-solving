#include <cstdio>
int main(void) {
	int T;
	scanf("%d", &T);
	while (T--) {
		int N, tmp;
		scanf("%d", &N);

		// N! 을 소인수분해했을 때 2의 승수 세기
		tmp = N;
		int twos = 0;
		while (tmp > 0) {
			twos += tmp / 2;
			tmp /= 2;
		}
		// N! 을 소인수분해했을 때 5의 승수 세기
		tmp = N;
		int fives = 0;
		while (tmp > 0) {
			fives += tmp / 5;
			tmp /= 5;
		}
		// 답 출력
		if (twos < fives) printf("%d\n", twos);
		else printf("%d\n", fives);
	}
	return 0;
}
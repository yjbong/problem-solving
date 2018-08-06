#include <cstdio>
#define MAXN 1000000
int s[1450]; // s[i] = 1+2+3+...+i
int ans[MAXN + 1]; // ans[i] = i원을 갖고 있을 때의 답
int main(void) {
	s[0] = 0;
	for (int i = 1; i < 1450; i++) s[i] = s[i - 1] + i;

	for (int i = 1; i <= MAXN; i++) { // 입력으로 들어올 수 있는 모든 i에 대하여,
		for (int j = 1; j < 1450; j++) { // 연속으로 집을 j개 구입하는 경우를 고려해 본다.
			if (i - s[j - 1] < 0) break;
			if (((i - s[j - 1]) / j >= 2) && ((i - s[j - 1]) % j == 0)) ans[i]++; // 가장 싼 집의 가격이 2이므로 몫이 2이상이라는 조건이 붙는다.
		}
	}

	while (1) {
		int N;
		scanf("%d", &N);
		if (N == 0) break;
		printf("%d\n", ans[N]); // 테스트 케이스마다 미리 계산한 답을 출력한다.
	}
	
	return 0;
}
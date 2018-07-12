#include <cstdio>
int N; // 학생 수
int A[100][10]; // A[i][j] = i번째 학생이 고른 j번째 문제의 답
int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 10; j++)
			scanf("%d", &A[i][j]);

	int ans = 0;
	for (int i = 0; i < N; i++) {
		bool perfect = true;
		for (int j = 0; j < 10; j++) {
			if (A[i][j] != j % 5 + 1) {
				perfect = false;
				break;
			}
		}
		if (perfect) printf("%d\n", i + 1);
	}
	return 0;
}
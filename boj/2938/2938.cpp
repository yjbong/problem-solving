#include <cstdio>
#include <vector>
#define MAXN 10000
using namespace std;
int N; // 수열의 크기
vector <int> A[3]; // A[i] = 3으로 나눈 나머지가 i인 수의 리스트
int main(void) {

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);
		A[a % 3].push_back(a);
	}

	int zeros = A[0].size(), ones = A[1].size(), twos = A[2].size();
	bool ok = true;
	if (ones > 0 && twos > 0 && zeros == 0) ok = false;
	if (zeros > ones + twos + 1) ok = false;

	if (!ok) printf("-1\n");
	else {
		int i, j, k;
		// 1을 먼저 쭉 쓰고, 그 다음 2를 쭉 쓰고, 0을 한 개씩 1이나 2의 사이에 넣으려고 한다.

		// 1과 2 사이에는 0이 반드시 1개 들어가야 하는데, 0의 개수가 적을 경우
		// 1의 사이에 차례대로 넣다보면 1과 2사이에는 못넣을 수 있으므로 그에 대한 처리
		if (ones > 0 && twos > 0 && zeros <= ones) {
			for (i = 0, j = 0, k = 0; i < zeros - 1; i++) { // 0을 한 개 남겨놓는다.
				printf("%d ", A[0][i]);
				printf("%d ", A[1][j++]);
			}
			for (; j < ones; j++) printf("%d ", A[1][j]); // 남은 1들을 출력
			printf("%d ", A[0][zeros - 1]); // 남겨놓았던 0 한 개를 출력
			for (; k < twos; k++) printf("%d ", A[2][k]); // 남은 2들을 출력
		}
		else {
			for (i = 0, j = 0, k = 0; i < zeros; i++) { // 그 외의 경우는 0을 되는대로 출력
				printf("%d ", A[0][i]);
				if (j < ones) printf("%d ", A[1][j++]);
				else if (k < twos) printf("%d ", A[2][k++]);
			}
			for (; j < ones; j++) printf("%d ", A[1][j]); // 남은 1들을 출력
			for (; k < twos; k++) printf("%d ", A[2][k]); // 남은 2들을 출력
		}
		printf("\n");
	}
	return 0;
}
#include <cstdio>
#include <cstring>
#define MAX_N 100000

int N; // 문자열의 길이
char S[MAX_N + 1]; // 문자열
int A[MAX_N]; // A[i] = S[i]를 중심으로 하는 가장 긴 팰린드롬의 반지름
char S2[MAX_N*2 + 1]; // dummy 문자를 포함한 문자열
int A2[MAX_N*2]; // A2[i] = S2[i]를 중심으로 하는 가장 긴 팰린드롬의 반지름

int min2(int a, int b) {
	return a < b ? a : b;
}

// Manacher's algorithm 구현
void Manacher(char S[], int A[]) {

	int R = -1; // j<i 인 모든 j 중 max(j+A[j]) 값
	int p = -1; // 그러한 R 값을 결정하는 j

	for (int i = 0; i < N; i++) {

		// A[i]의 초기값 결정
		if (i <= R) A[i] = min2(R - i, A[2 * p - i]);
		else A[i] = 0;

		// A[i] 업데이트
		while (i - A[i] - 1 >= 0 && i + A[i] + 1 < N && S[i - A[i] - 1] == S[i + A[i] + 1]) A[i]++;
		
		// 다음 iteration을 위해 R과 p를 업데이트
		if (R < i + A[i]) {
			R = i + A[i];
			p = i;
		}
	}
}

int main(void) {

	int ans = 0;
	scanf("%s", S);

	// S에 대해 Manacher 알고리즘을 실행하고 답을 구한다. 
	N = strlen(S);
	Manacher(S, A);
	for (int i = 0; i < N; i++) {
		if (ans < A[i] * 2 + 1) ans = A[i] * 2 + 1;
	}

	// 그런데 Manacher 알고리즘은 홀수 길이의 팰린드롬만 찾을 수 있기 때문에,
	// 문자 사이마다 더미 문자(#)를 넣은 문자열을 만들고 Manacher 알고리즘을
	// 실행하여 짝수 길이 팰린드롬을 찾는다.
	for (int i = 0, j = 0; i < N; i++) {
		S2[j++] = S[i];
		if (i < N - 1) S2[j++] = '#';
		else S2[j++] = '\0';
	}
	N = strlen(S2);
	Manacher(S2, A2);
	for (int i = 0; i < N; i++) {
		if (S2[i] == '#') {
			if (ans < (A2[i] + 1) / 2 * 2) ans = (A2[i] + 1) / 2 * 2;
		}
	}

	// 답 출력
	printf("%d\n", ans);
	return 0;
}
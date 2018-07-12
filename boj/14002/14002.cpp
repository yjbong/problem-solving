#include <cstdio>
#define MAXN 1000
int N; // 수열의 길이
int A[MAXN]; // 수열
int D[MAXN]; // D[i] = A[i]를 마지막으로 하는 LIS의 길이
int pre[MAXN]; // pre[i] = A[i]가 속한 증가 수열에서, A[i] 바로 앞에 있는 원소의 idx
               // (즉, 증가 수열에서 A[pre[i]]가 A[i] 바로 앞에 있음)
int lis[MAXN];
int lisLen;

int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);

	// D 초기화
	for (int i = 0; i < N; i++) D[i] = 1;
	// pre 초기화
	for (int i = 0; i < N; i++) pre[i] = -1;

	// DP
	int lisIdx = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (A[j] < A[i] && D[i] < D[j] + 1) {
				D[i] = D[j] + 1;
				pre[i] = j;
			}
		}
		if (D[lisIdx] < D[i]) lisIdx = i;
	}

	// LIS 구하기
	lisLen = 0;
	while (lisIdx >= 0){
		lis[lisLen++] = A[lisIdx];
		lisIdx = pre[lisIdx];
	}

	// LIS 출력
	printf("%d\n", lisLen);
	for (int i = lisLen - 1; i >= 0; i--) printf("%d ", lis[i]); // LIS는 역순으로 저장되어 있으므로 거꾸로 출력
	printf("\n");

	return 0;
}
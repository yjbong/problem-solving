#include <cstdio>
#include <cstring>
#include <cassert>
#define MAXN 60
int n;
char a[MAXN + 1];
char b[MAXN + 1];
int bCnt[10];

int ans[MAXN];

// b의 자릿수를 적절히 바꿔서 0으로 시작하지 않는 a이상인 가장 작은 수를 구함
int getSmallestBigger(int idx, char a[], int bCnt[10]) {
	if (idx >= n) return 1;

	int curDgt = a[idx] - '0';
	int i, j, k, p;
	for (i = curDgt; i < 10; i++) if (bCnt[i] > 0) break;
	if (i > 9) return 0; // 현재 a의 최상위 자릿수보다 크거나 같은 숫자가 남아있지 않다면 불가능

	// 현재 자리에 a와 같은 자릿수를 대입
	if (bCnt[curDgt] > 0) {
		bCnt[curDgt]--;
		if (getSmallestBigger(idx + 1, a, bCnt)) {
			ans[idx] = curDgt;
			return 1;
		}
		bCnt[curDgt]++;
	}

	for (i = curDgt + 1; i < 10; i++) if (bCnt[i] > 0) break;
	if (i > 9) return 0; // 현재 자리에 a의 자릿수와 같은 숫자를 대입할 수 없는데(그게 가능했다면 이 코드는 실행되지 않음)
						 // a의 자릿수보다 큰 숫자가 남아 있지 않다면 불가능

	// 현재 자리에 a보다 큰 자릿수를 대입
	for (i = curDgt + 1; i < 10; i++) {
		if (bCnt[i] > 0) {
			ans[idx] = i;
			bCnt[i]--;
			// 현재 자릿수보다 하위인 자릿수들은 최대한 작게 만듬
			for (j = 0, p = idx + 1; j < 10; j++)
				for (k = 0; k < bCnt[j]; k++) ans[p++] = j;

			break;
		}
	}
	return 1;
}

// b의 자릿수를 적절히 바꿔서 0으로 시작하지 않는 a이하인 가장 큰 수를 구함
int getBiggestSmaller(int idx, char a[], int bCnt[10]) {
	if (idx >= n) return 1;

	int curDgt = a[idx] - '0';
	int i, j, k, p;
	for (i = curDgt; i >= 0; i--) if (bCnt[i] > 0) break;
	if (i < 0) return 0; // 현재 a의 최상위 자릿수보다 작거나 같은 숫자가 남아있지 않다면 불가능
	else if (i == 0 && idx == 0) return 0; // 남은 숫자가 0밖에 없는데 현재 자릿수가 최상위라면 불가능

	// 현재 자리에 a와 같은 자릿수를 대입
	if (bCnt[curDgt] > 0) {
		bCnt[curDgt]--;
		if (getBiggestSmaller(idx + 1, a, bCnt)) {
			ans[idx] = curDgt;
			return 1;
		}
		bCnt[curDgt]++;
	}

	for (i = curDgt - 1; i >= 0; i--) if (bCnt[i] > 0) break;
	if (i < 0) return 0; // 현재 자리에 a의 자릿수와 같은 숫자를 대입할 수 없는데(그게 가능했다면 이 코드는 실행되지 않음)
						 // a의 자릿수보다 작은 숫자가 남아 있지 않다면 불가능
	else if (i == 0 && idx == 0) return 0; // 남은 숫자가 0밖에 없는데 현재 자릿수가 최상위라면 불가능

	// 현재 자리에 a보다 작은 자릿수를 대입
	for (i = curDgt - 1; i >= 0; i--) {
		if (bCnt[i] > 0) {
			ans[idx] = i;
			bCnt[i]--;
			// 현재 자릿수보다 하위인 자릿수들은 최대한 크게 만듬
			for (j = 9, p = idx + 1; j >= 0; j--) 
				for (k = 0; k < bCnt[j]; k++) ans[p++] = j;
			
			break;
		}
	}
	return 1;
}

int main(void) {
	scanf("%s", a);
	scanf("%s", b);
	assert(strlen(a) == strlen(b));

	n = strlen(a);
	for (int i = 0; i < n; i++) bCnt[b[i] - '0']++;

	// a 이상이면서 가장 작은 수 구하기
	if (getSmallestBigger(0, a, bCnt)) {
		for (int i = 0; i < n; i++) printf("%d", ans[i]);
		printf("\n");
	}
	else printf("0\n");

	// a 미만이면서 가장 큰 수 구하기
	// a = a-1
	a[n - 1]--;
	int idx = n - 1;
	while (idx > 0 && a[idx] < '0') {
		a[idx] += 10;
		a[idx - 1]--;
		idx--;
	}

	// bCnt 복원
	for (int i = 0; i < 10; i++) bCnt[i] = 0;
	for (int i = 0; i < n; i++) bCnt[b[i] - '0']++;

	if (a[0] >= '1' && getBiggestSmaller(0, a, bCnt)) { // a = a-1 을 했을 때 최상위 자리가 0이 되어서는 안됨
		for (int i = 0; i < n; i++) printf("%d", ans[i]);
		printf("\n");
	}
	else printf("0\n");
	
	return 0;
}
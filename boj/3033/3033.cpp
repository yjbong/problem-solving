#include <cstdio>
#include <vector>
#define MOD 100007
using namespace std;

int N;
char L[200000 + 1];
int pow26[200000 + 1]; // pow26[i] = (26^i) % MOD

vector <int> hashTable[MOD]; // hashTable[i] = 해쉬값이 i인 문자열들의 시작 위치 목록

bool isPossible(int len) {
	if (len == 0) return true;

	bool duplicated = false; // 2번 이상 등장하는 길이가 len인 문자열이 있는지 여부 (겹쳐서 등장할 수도 있음)

	for (int i = 0; i < MOD; i++) hashTable[i].clear();

	// 0번 문자부터 시작하는 길이 len인 문자열의 해쉬값 계산
	int curHashValue = 0;
	for (int i = 0; i < len; i++) {
		curHashValue = (curHashValue * 26) % MOD;
		curHashValue = (curHashValue + L[i] - 'a') % MOD;
	}
	hashTable[curHashValue].push_back(0);

	// 길이 len인 다른 문자열들의 해쉬값들을 계산
	for (int i = 1; i + len - 1 < N; i++) {
		// i번 문자부터 시작하는 길이 len인 문자열의 해쉬값 계산 (i-1번 문자부터 시작하는 문자열의 해쉬값 이용)
		curHashValue = (curHashValue - (pow26[len - 1] * (L[i - 1] - 'a')) % MOD + MOD) % MOD;
		curHashValue = (curHashValue * 26) % MOD;
		curHashValue = (curHashValue + L[i + len - 1] - 'a') % MOD;
		
		// 현재와 해쉬값이 일치하는 문자열 시작 위치가 있는 경우, 일일이 비교해 봄 
		for (int j = 0; j < hashTable[curHashValue].size(); j++) {
			int pos = hashTable[curHashValue][j];
			int cnt, k = pos, l = i;
			for (cnt=0; cnt < len; cnt++, k++, l++)
				if (L[k] != L[l]) break;
			
			// 2번 이상 등장하는 문자열이 있는 경우
			if (cnt == len) {
				duplicated = true;
				break;
			}
		}
		if (duplicated) break;

		hashTable[curHashValue].push_back(i);
	}

	return duplicated;
}

int main(void) {
	scanf("%d\n", &N);
	fgets(L, 200000, stdin);

	pow26[0] = 1;
	for (int i = 1; i < N; i++) pow26[i] = (pow26[i - 1] * 26) % MOD;

	// ans를 이분 탐색으로 찾음
	int ans = 0;
	int left = 1, right = N;
	while (left <= right) {
		int mid = (left + right) / 2;
		// 2번 이상 등장하는 길이가 mid인 문자열이 있는 경우
		if (isPossible(mid)) {
			if (ans < mid) ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	printf("%d\n", ans);

	return 0;
}
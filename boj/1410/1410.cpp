#include <cstdio>
#include <cstring>
#define MAXN 15
#define MAXL 50
int N; // 패턴의 개수
int K; // 일치해야 하는 패턴의 개수
int L; // 패턴의 길이
char P[MAXN][MAXL+1]; // P[i] = i번째 패턴

// go(idx, stat) = 만들려는 문자열의 idx번째 문자를 결정할 차례이고,
//                 고려할 수 있는 패턴의 집합(비트마스크)이 stat이면서,
//                 비트마스크에 속한 패턴 중 정확히 K개가 일치하는 문자열의 개수
int cache[MAXL + 1][1 << MAXN];
int go(int idx, int stat) {
	if (cache[idx][stat] >= 0) return cache[idx][stat]; // memoization

	int result = 0;
	if (idx == L) {
		int statBits = 0;
		for (int i = 0; i < N; i++) if (stat & (1 << i)) statBits++;
		// 모든 문자를 결정한 후, 일치하는 패턴의 개수가 정확히 K개가 되는지 확인
		if (statBits == K) result = 1;
		else result = 0;
		return (cache[idx][stat]=result);
	}

	for (char ch = 'a'; ch<='z'; ch++) { // idx번 문자에 'a'~'z'를 대입해 본다.
		int newStat = 0; // idx번 문자를 ch로 했을 때 앞으로 가능한 패턴의 집합
		int newStatBits = 0; // newStat에서 1로 set된 비트의 개수
		for (int i = 0; i < N; i++) {
			if (stat & (1 << i)) { // i번째 패턴과 일치할 가능성이 있을 때
				if (P[i][idx] == '?' || P[i][idx] == ch) { // 문자열의 idx번째 문자를 ch로 했을 때 i번째 패턴의 idx번 문자와 일치  
					newStat |= (1 << i);
					newStatBits++;
				}
			}
		}
		if (newStatBits < K) continue; // 고려할 수 있는 패턴이 이미 K개 미만이라면 K개 일치할 가능성은 전혀 없으므로 스킵
		result = (result + go(idx + 1, newStat)) % 1000003;
	}

	return (cache[idx][stat] = result);
}

int main(void) {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) scanf("%s", P[i]);
	L = strlen(P[0]);

	// cache 초기화
	for (int i = 0; i <= L; i++)
		for (int j = 0; j < (1 << N); j++) cache[i][j] = -1;

	// 답 출력
	printf("%d\n", go(0, (1 << N) - 1));

	return 0;
}
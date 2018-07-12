#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100
using namespace std;

typedef struct {
	int length;
	int v0;
	int v1;
}LINE;

int N; // 컴퓨터의 개수
char input[MAXN][MAXN + 1];

LINE line[MAXN*MAXN]; int lines;
bool cmp(LINE a, LINE b) {
	if (a.length < b.length) return true;
	else if (a.length > b.length) return false;
	else {
		if (a.v0 < b.v0) return true;
		else if (a.v0 > b.v0) return false;
		else {
			if (a.v1 <= b.v1) return true;
			else return false;
		}
	}
}

// Union Find
int p[MAXN]; // p[i] = i의 parent (이 값이 음수라면 i가 root인 것이고, 집합의 height는 -p[i])
// init2(N)
void init2(int N) {
	for (int i = 0; i < N; i++) p[i] = -1;
}
// find2(i) = i가 속한 집합의 root 리턴
int find2(int i) {
	while (p[i] >= 0) i = p[i];
	return i;
}
// union2(i, j) = i가 속한 집합과 j가 속한 집합을 합침 (동작을 하면 true, 아니면 false)
bool union2(int i, int j) {
	int ri = find2(i);
	int rj = find2(j);
	if (ri == rj) return false; // i와 j가 이미 같은 집합인 경우 아무 것도 하지 않음

	if (p[ri] < p[rj]) { // i가 속한 집합의 height가 j가 속한 집합의 height 보다 큰 경우
		p[rj] = ri; // j집합이 i집합에 합쳐짐
		// i집합의 height는 변하지 않음
	}
	else if (p[ri] > p[rj]){ // i가 속한 집합의 height가 j가 속한 집합의 height 보다 작은 경우
		p[ri] = rj; // i집합이 j집합에 합쳐짐
		// j집합의 height는 변하지 않음
	}
	else { // i가 속한 집합의 height가 j가 속한 집합의 height 와 같은 경우
		p[rj] = ri; // j집합이 i집합에 합쳐짐
		p[ri]--; // i집합의 height가 1 증가
	}
	return true;
}

// Minimum Spanning Tree 의 길이 합 리턴
int kruskal(int N) {
	
	int result = 0;

	init2(N);
	for (int i = 0; i < lines; i++) { // 길이가 짧은 랜선부터
		if (union2(line[i].v0, line[i].v1)) result += line[i].length; // v0과 v1이 아직 연결되지 않았다면 이 랜선을 MST에 추가
	}

	// 모든 컴퓨터가 연결되었는지 검사
	int sets = 0;
	for (int i = 0; i < N; i++) if (p[i] < 0) sets++;
	if (sets > 1) return -1; // 모든 컴퓨터가 연결되었다면 이 때 집합은 1개만 있어야 함
	
	return result;
}

int main(void) {

	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%s", input[i]);
	
	// 입력으로부터 랜선 추가
	lines = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (input[i][j] == '0') continue;
			else if (input[i][j] >= 'a' && input[i][j] <= 'z') line[lines].length = input[i][j] - 'a' + 1;
			else if (input[i][j] >= 'A' && input[i][j] <= 'Z') line[lines].length = input[i][j] - 'A' + 27;

			line[lines].v0 = i, line[lines].v1 = j;
			lines++;
		}
	}

	// 랜선을 길이의 오름차순으로 정렬
	sort(line, line + lines, cmp);

	int totalLength = 0; // 모든 랜선 길이의 합
	for (int i = 0; i < lines; i++) totalLength += line[i].length;

	// MST 계산
	int mstLength = kruskal(N);

	// 답 출력
	if (mstLength < 0) printf("-1\n"); // 모든 컴퓨터가 연결되지 않은 경우
	else printf("%d\n", totalLength - mstLength);

	return 0;
}
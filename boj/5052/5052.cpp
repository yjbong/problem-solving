#include <cstdio>
#include <cstring>
#include <cassert>
#define MAXN 10000 // 전화번호의 최대 개수
#define MAXLEN 10 // 각 전화번호의 최대 길이

int t; // 테스트 케이스 수
int N; // 전화번호의 수
char number[MAXN][MAXLEN + 1]; // number[i] = i번째 전화번호

typedef struct {
	int digit; // 현재 노드가 나타내는 전화번호의 마지막 숫자
	int next[10]; // next[i-'0'] = 현재 노드에서 다음 숫자가 i일 때 이동할 노드의 idx
	bool isComplete; // 현재 노드가 나타내는 번호가 완결된 것이라면 true
	int prev; // 현재 노드의 부모 노드 idx
}NODE;

NODE trie[MAXN*MAXLEN + 1]; int nodes;

void initTrie() {
	// 트라이의 root node(trie[0]) 초기화
	for (int i = 0; i < 10; i++) trie[0].next[i] = -1; // 모든 숫자에 대해 다음 노드가 아직 없는 것으로 초기화
	trie[0].prev = -1;
	trie[0].isComplete = false;
	nodes = 1;
}

// trie에 새로운 전화번호를 추가한다.
void addNumber(char number[]) {
	int len = strlen(number);
	int curNode = 0;
	for (int i = 0; i < len; i++) {
		if (trie[curNode].next[number[i] - '0'] < 0) { // 노드를 추가해야 하는 경우
			int newNode = nodes++;
			// newNode 초기화
			trie[newNode].digit = number[i] - '0';
			trie[newNode].isComplete = i == len - 1 ? true : false;
			for (int j = 0; j < 10; j++) trie[newNode].next[j] = -1;
			// newNode와 curNode 연결
			trie[curNode].next[number[i] - '0'] = newNode;
			trie[newNode].prev = curNode;
			// curNode를 newNode로 갱신
			curNode = newNode;
		}
		else {
			curNode = trie[curNode].next[number[i] - '0'];
			if (i == len - 1) trie[curNode].isComplete = true;
		}
	}
}

// trie에 현재 전화번호의 prefix에 해당하는 다른 전화번호가 있다면 true
bool hasPrefix(char number[]) {
	int len = strlen(number);
	int curNode = 0;
	for (int i = 0; i < len-1; i++) { // number 자신을 제외한 모든 길이 prefix에 대해서 존재 여부 검사
		assert(trie[curNode].next[number[i] - '0'] >= 0); // addNumber가 제대로 되었다면 이 조건을 만족
		curNode = trie[curNode].next[number[i] - '0'];
		if (trie[curNode].isComplete) return true;
	}
	return false;
}

int main(void) {

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) scanf("%s", number[i]);

		// 트라이 초기화
		initTrie();
		// 트라이에 주어진 전화번호들을 입력
		for (int i = 0; i < N; i++) addNumber(number[i]);
		// 전화번호 목록의 일관성 확인
		bool isConsistent = true;
		for (int i = 0; i < N; i++) {
			if (hasPrefix(number[i])) {
				isConsistent = false;
				break;
			}
		}
		// 답 출력
		if (isConsistent) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
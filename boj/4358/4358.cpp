#include <cstdio>
#include <cstring>
#include <vector>

#define MAXLEN 30 // 나무 이름의 최대 길이
#define MAXKIND 10000 // 나무의 최대 가짓수
using namespace std;

char tree[MAXLEN + 1];
int trees; // 나무의 개수

typedef struct {
	int next[128]; // ASCII 코드 개수 = 128
	int count;
}NODE;

vector <NODE> trie;
int trieNodes;

void addTree(int letterIdx, int len, int trieIdx) {

	if (letterIdx == len) {
		trie[trieIdx].count++;
		return;
	}

	int nextIdx = tree[letterIdx];
	if (trie[trieIdx].next[nextIdx] < 0) { // 현재 노드에서 해당 문자가 들어왔을 때 이동할 노드가 정의되지 않은 경우

		// 새로 추가할 노드 생성
		NODE newNode;
		for (int i = 0; i < 128; i++) newNode.next[i] = -1;
		newNode.count = 0;

		// 새로운 노드를 추가하고 연결
		trie.push_back(newNode);
		int newNodeIdx = trie.size() - 1;
		trie[trieIdx].next[nextIdx] = newNodeIdx;
		addTree(letterIdx + 1, len, newNodeIdx);
	}
	else addTree(letterIdx + 1, len, trie[trieIdx].next[nextIdx]);
}

char cur[MAXLEN + 1];
void traverse(int letterIdx, int trieIdx) {
	if (trie[trieIdx].count > 0) {
		for (int i = 0; i < letterIdx; i++) printf("%c", cur[i]);
		printf(" %.4lf\n", (100.0*trie[trieIdx].count)/trees);
	}
	for (int i = 0; i < 128; i++) {
		if (trie[trieIdx].next[i] >= 0) {
			cur[letterIdx] = i;
			traverse(letterIdx + 1, trie[trieIdx].next[i]);
		}
	}
}

int main(void) {

	// 트라이에는 기본으로 루트 노드가 있어야 하며 루트 노드의 번호는 0번이다.
	NODE root;
	for (int i = 0; i < 128; i++) root.next[i] = -1;
	root.count = 0;
	trie.push_back(root);

	// 입력
	trees = 0;
	while (scanf("%[^\n]\n", tree) == 1) {
		trees++;
		addTree(0, strlen(tree), 0); // 입력받은 나무 이름을 트라이에 추가한다. 
	}

	// 답 출력
	traverse(0,0);
	return 0;
}
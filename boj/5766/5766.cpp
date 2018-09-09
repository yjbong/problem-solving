#include <cstdio>
#include <utility>
#include <algorithm>
#define PLAYERS 10000
using namespace std;
typedef pair<int, int> ii; // first: score, second: player id
ii info[PLAYERS];

bool compare(ii a, ii b) {
	if (a.first > b.first) return true;
	else if (a.first == b.first && a.second < b.second) return true;
	else return false;
}

int main(void) {
	while (1) {
		int N, M;
		scanf("%d %d", &N, &M);
		if (N == 0 && M == 0) break;

		for (int i = 0; i < PLAYERS; i++) {
			info[i].first = 0;
			info[i].second = i + 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int curPlayer;
				scanf("%d", &curPlayer);
				info[curPlayer - 1].first++;
			}
		}

		sort(info, info + PLAYERS, compare);
		// ���� ���ǿ��� 1���� �� 1���̶� �߰�, ���� �� 1���� info[0] �� �ְ� �ȴ�. ���� 2���� info[1]���� �ִ�.
		int _2ndScore = info[1].first;
		for (int i = 1; i < PLAYERS; i++) {
			if (info[i].first != _2ndScore) break;
			printf("%d ", info[i].second);
		}
		printf("\n");
	}
	return 0;
}
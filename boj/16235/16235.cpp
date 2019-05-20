#include <cstdio>
#include <deque>
#include <utility>
#define MAX_N 10
using namespace std;
int N; // 땅은 N*N크기
int M; // 초기 나무의 수
int K; // 시뮬레이션 년수
int A[MAX_N][MAX_N]; // A[x][y] = 겨울에 로봇이 셀(x,y)에 추가하는 양분
int E[MAX_N][MAX_N]; // E[x][y] = 현재 셀(x,y)에 있는 양분

typedef pair<int, int> ii; // first: 나무의 나이, second: 동일한 나이를 가진 나무의 수
deque <ii> tree[MAX_N][MAX_N]; // tree[i] = 셀(i,j)에 있는 나무의 정보
int min2(int a, int b) { return a < b ? a : b; }
void yearSim() {

	deque<ii>::iterator it;

	// 봄, 여름
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			bool allDie = false; // allDie가 true이면 앞으로 나오는 나무들은 모두 죽은 것임
			for (it = tree[i][j].begin(); it != tree[i][j].end(); it++) {

				int curAge = it->first;
				int curTrees = it->second;

				if (allDie) {
					E[i][j] += (curAge / 2) * curTrees; // 나무들이 모두 죽어서 양분이 됨
					it->second = 0;
					continue;
				}

				int newTrees = min2(E[i][j] / curAge, curTrees);				
				if (newTrees < curTrees) { // 셀(i,j)에서 나이가 curAge인 나무가 죽게 됨
					E[i][j] -= curAge * newTrees; // 살아남은 curAge인 나무들 각각이 나이만큼 양분을 소비  
					it->second = newTrees;
					E[i][j] += (curAge / 2)*(curTrees - newTrees); // 여름에 일부 죽은 나무가 양분으로 추가
					allDie = true;
				}
				else E[i][j] -= curAge * curTrees;
			}

			while (!tree[i][j].empty()) {
				ii b = tree[i][j].back();
				if (b.second == 0) tree[i][j].pop_back();
				else break;
			}

			for (it = tree[i][j].begin(); it != tree[i][j].end(); it++) it->first++; // 살아남은 나무들의 나이가 1씩 증가
		}
	}

	// 가을
	const int dx[8] = { -1, 0, 1,-1, 1,-1, 0, 1};
	const int dy[8] = { -1,-1,-1, 0, 0, 1, 1, 1 };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (it = tree[i][j].begin(); it != tree[i][j].end(); it++) {
				int curAge = it->first;
				int curTrees = it->second;
				// 나무의 나이가 5의 배수라면 주변 칸에 번식
				if (curAge > 0 && (curAge % 5 == 0)) {
					for (int k = 0; k < 8; k++) {
						int cx = i + dx[k];
						int cy = j + dy[k];
						if (cx >= 0 && cx < N && cy >= 0 && cy < N) {
							if ((!tree[cx][cy].empty()) && tree[cx][cy].front().first == 1) tree[cx][cy].front().second += curTrees;
							else tree[cx][cy].push_front(make_pair(1, curTrees));
						}
					}
				}
			}
		}
	}

	// 겨울
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) E[i][j] += A[i][j]; // 로봇이 양분 추가
}
int main(void) {

	scanf("%d %d %d", &N, &M, &K);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) scanf("%d", &A[i][j]);
	for (int i = 0; i < M; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		x--; y--;
		tree[x][y].push_front(make_pair(z, 1)); // 셀(x,y)에 나이가 z인 나무 1개 추가 
	}
	
	// 시뮬레이션
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) E[i][j] = 5; // 최초에는 모든 셀에 양분이 5만큼 있음

	for (int i = 0; i < K; i++) yearSim(); // K년간 시뮬레이션

	// 남아있는 나무의 수 확인
	deque<ii>::iterator it;
	int ans = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (it = tree[i][j].begin(); it != tree[i][j].end(); it++)
				ans += it->second;
	printf("%d\n", ans);

	return 0;
}
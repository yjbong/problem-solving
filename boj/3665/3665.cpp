#include <cstdio>
#define MAXN 500
int T; // 테스트 케이스 수
int N; // 팀의 수
int M; // 상대적인 등수가 바뀐 쌍의 수
int place[MAXN+1]; // place[i] = 지난 대회에서 i등을 한 팀의 번호
bool win[MAXN + 1][MAXN + 1]; // win[i][j] = 팀 i가 j보다 순위가 높으면 true, 아니면 false
int indegree[MAXN + 1]; // inDegree[i] = 팀 i보다 순위가 높은 팀의 수
bool check[MAXN + 1];
int ans[MAXN];

int main(void) {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);

		// 등수 입력
		for (int i = 1; i <= N; i++) scanf("%d", &place[i]);

		// 등수에 따라 win 배열 구성
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				win[i][j] = false;

		for (int i = 1; i <= N; i++) indegree[i] = 0;

		for (int i = 1; i <= N; i++) { // i등인 팀에 대해,
			for (int j = i + 1; j <= N; j++) { // i등보다 뒤에 있는 모든 팀들을 업데이트
				win[place[i]][place[j]] = true;
				indegree[place[j]]++;
			}
		}

		// 상대적 등수가 바뀐 쌍 입력
		scanf("%d", &M);
		for (int i = 0; i < M; i++) {
			int team1, team2;
			scanf("%d %d", &team1, &team2);

			// 원래 team1이 team2보다 높은 등수인 경우
			if (win[team1][team2]) {
				win[team1][team2] = false;
				indegree[team2]--;
				win[team2][team1] = true;
				indegree[team1]++;
			}
			// 원래 team2가 team1보다 높은 등수인 경우
			else {
				win[team2][team1] = false;
				indegree[team1]--;
				win[team1][team2] = true;
				indegree[team2]++;
			}
		}

		// 위상정렬
		bool impossible = false, vague = false;
		for (int i = 1; i <= N; i++) check[i] = false;

		for (int iter = 0; iter < N; iter++) {
			int curPossibles = 0, curPossibleIdx;
			for (int i = 1; i <= N; i++) {
				if (check[i]==false && indegree[i] == 0) {
					curPossibles++;
					curPossibleIdx = i;
				}
			}
			if (curPossibles == 0) { impossible = true; break; } // 더 이상 위상정렬이 불가능하면 중단
			else if (curPossibles > 1) { vague = true; break; } // 위상정렬 결과가 유일하지 않다면 중단

			// 위상정렬 결과 업데이트
			ans[iter] = curPossibleIdx;
			check[curPossibleIdx] = true;

			// 현재 점에 있는 outedge들을 제거
			for (int i = 1; i <= N; i++) {
				if (win[curPossibleIdx][i]) {
					win[curPossibleIdx][i] = false;
					indegree[i]--;
				}
			}
		}

		// 답 출력
		if (impossible) printf("IMPOSSIBLE\n");
		else if (vague) printf("?\n");
		else {
			for (int i = 0; i < N; i++) printf("%d ", ans[i]);
			printf("\n");
		}
	}
	return 0;
}
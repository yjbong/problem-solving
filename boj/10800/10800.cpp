#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>
#define MAX_N 200000

using namespace std;
//typedef pair <int, int> ii; // first : 크기, second : 색깔
typedef pair<pair<int, int>, int> iii; // first.first : 크기, first.second : 색깔, second : 원래 입력에서의 idx

int N; // 공의 개수
iii ball[MAX_N+1]; // ball[i] = i번째 공 (i는 1부터 시작)

vector <int> sameColor[MAX_N+1]; // sameColor[i] = i색인 공들의 ball 배열에서의 인덱스 위치
int pre[MAX_N + 1]; // pre[i] = i번 공의 답을 구하기 위해 알아야 하는 공의 위치 (이 값이 -1이면 그런 공이 없는 것이다)
int pres[MAX_N + 1]; // pres[i] = pre[i]와 색과 크기가 같은 공의 개수 (pre[i]를 포함)

int lastSmaller[MAX_N + 1]; // lastEdible[i] = i번 공보다 크기가 작으면서 가장 인덱스가 큰 공의 위치

int sum[MAX_N + 1]; // sum[i] = 1~i번 공의 크기의 합

int score[MAX_N + 1]; // score[i] = i번 공이 얻을 수 있는 점수

int printOrder[MAX_N + 1]; // score를 출력하는 순서 (원래 idx 기준으로 출력해야 하므로)

int main(void){
	scanf("%d", &N);
	for (int i = 1; i <= N; i++){
		scanf("%d %d", &ball[i].first.second, &ball[i].first.first);
		ball[i].second = i;
	}

	// ball들을 무게 오름차순, 색깔 오름차순으로 정렬
	sort(ball+1, ball + 1+ N);

	// sameColor 배열 구하기
	for (int i = 1; i <= N; i++) sameColor[ball[i].first.second].push_back(i);

	// pre 배열 구하기
	for (int i = 1; i <= N; i++){
		int curSames = 0; // 현재 색깔에서 가장 최근 등장한 무게가 동일하게 몇 번 나왔는지 저장
		int oldSames = 0; // 직전 등장 무게의 curSames 값
		for (int j = 0; j < sameColor[i].size(); j++){
			int curIdx = sameColor[i][j];

			if (j == 0){
				pre[curIdx] = 0; // 특정 색깔에서 가장 작은 공은 pre에 해당하는 index가 없음
				curSames = 1;
			}
			else{
				int oldIdx = sameColor[i][j - 1];
				if (ball[oldIdx].first.first == ball[curIdx].first.first){
					pre[curIdx] = pre[oldIdx];
					pres[curIdx] = oldSames;
					curSames++;
				}
				else{
					pre[curIdx] = oldIdx;
					pres[curIdx] = curSames;

					oldSames = curSames;
					curSames = 1;
				}
			}
		}
	}

	// lastSmaller 배열 구하기
	for (int i = 1; i <= N; i++){
		if (i == 1) lastSmaller[i] = 0; // 가장 작은 원소는 lastSmaller가 없음
		else{
			if (ball[i - 1].first.first == ball[i].first.first){
				lastSmaller[i] = lastSmaller[i - 1];
			}
			else{
				lastSmaller[i] = i - 1;
			}
		}
	}

	// sum 배열 구하기
	sum[0] = 0;
	for (int i = 1; i <= N; i++) sum[i] = sum[i - 1] + ball[i].first.first;

	score[0] = 0; // 0번 공은 없으나 이렇게 초기화하면 답에 영향을 안 준다
	for (int i = 1; i <= N; i++){
		score[i] = score[pre[i]] + sum[lastSmaller[i]] - (pre[i] > 0 ? sum[lastSmaller[pre[i]]] : 0) - (pre[i] > 0 ? pres[i] * ball[pre[i]].first.first : 0);
	}

	// printOrder 배열 구하기
	for (int i = 1; i <= N; i++){
		printOrder[ball[i].second] = i;
	}

	/*
	for (int i = 1; i <= N; i++) printf("color = %d, size = %d, idx = %d\n", ball[i].first.second, ball[i].first.first, ball[i].second);

	for (int i = 1; i <= N; i++){
		if (sameColor[i].size()>0){
			printf("Color %d : ", i);
			for (int j = 0; j < sameColor[i].size(); j++){ printf("%d ", sameColor[i][j]); }
			printf("\n");
		}
	}

	for (int i = 1; i <= N; i++)
		printf("pre[%d] = %d\n", i, pre[i]);

	for (int i = 1; i <= N; i++)
		printf("pres[%d] = %d\n", i, pres[i]);

	for (int i = 1; i <= N; i++)
		printf("lastSmaller[%d] = %d\n", i, lastSmaller[i]);
	*/

	// 답 출력
	for (int i = 1; i <= N; i++)
		printf("%d\n", score[printOrder[i]]);

	return 0;
}
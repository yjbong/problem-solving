#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#define MAX_R 50
#define MAX_C 50
#define MAX_CAR 100
#define MAX_PARK 100
#define BLANK -1
#define WALL -2
#define INF 1000000000

using namespace std;

typedef struct {
	int y;
	int x;
}POS;
char board[MAX_R + 2][MAX_C + 2];
int boardInfo[MAX_R + 2][MAX_C + 2]; // 0 ~ numCar-1 --> C, MAX_CAR ~ MAX_CAR+numPark-1 --> P
int R;
int C;
int numCar, numPark;
POS carPos[MAX_CAR];

int dist[MAX_CAR][MAX_PARK]; // dist[i][j] = i번 차로부터 j번 주차구역까지의 거리

queue <POS> q;
int curDist[MAX_R + 2][MAX_C + 2];
const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,1,-1 };

#define MAX_V MAX_CAR+MAX_PARK+2

// 0번 : source, 1~numCar번 : 차, numCar+1~numCar+numPark번 : 주차구역, numCar+numPark+1번 : sink
int capacity[MAX_V][MAX_V], flow[MAX_V][MAX_V];

void initNetwork(int threshold) {
	int source = 0;
	int sink = numCar + numPark + 1;
	memset(capacity, 0, sizeof(capacity));
	for (int i = 1; i <= numCar; i++) capacity[source][i] = 1;
	for (int i = numCar + 1; i <= numCar + numPark; i++) capacity[i][sink] = 1;

	// threshold값에 따른 간선 연결
	for (int i = 0; i < numCar; i++) {
		for (int j = 0; j < numPark; j++) {
			int carIdx = i + 1;
			int parkIdx = j + numCar + 1;
			if (dist[i][j] <= threshold) capacity[carIdx][parkIdx] = 1;
		}
	}
}

int getMaxFlow() {
	memset(flow, 0, sizeof(flow));
	int totalFlow = 0;
	int source = 0;
	int sink = numCar + numPark + 1;
	while (true) {
		// BFS로 증가 경로 찾기
		vector <int> parent(MAX_V, -1);
		queue<int> q;
		parent[source] = source; // source의 parent(이전 정점)는 source 자신
		q.push(source);
		while (!q.empty()) {
			int here = q.front(); q.pop();
			for (int there = source; there <= sink; there++) {
				// 잔여 용량이 남아 있는 간선을 따라 탐색
				if (capacity[here][there] - flow[here][there] > 0 && parent[there] == -1) {
					q.push(there);
					parent[there] = here;
				}
			}
		}
		// 증가 경로가 없으면 종료
		if (parent[sink] == -1) break;

		// 증가 경로를 찾았다면 이 경로로 얼마나 유량을 보낼 수 있는지 확인
		int amount = INF;
		for (int p = sink; p != source; p = parent[p]) {
			amount = min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
		}

		// 증가 경로로 유량을 보냄
		if(amount>0)
		for (int p = sink; p != source; p = parent[p]) {
			flow[parent[p]][p] += amount;
			flow[p][parent[p]] -= amount;
		}

		totalFlow += amount;
	}
	//printf("totalFlow = %d\n", totalFlow);
	return totalFlow;
}

int main(void) {

	// 입력
	scanf("%d %d\n", &R, &C);
	for (int i = 1; i <= R; i++) {
		scanf("%[^\n]\n", board[i] + 1);
	}
	for (int i = 0; i <= R + 1; i++) board[i][0] = board[i][C + 1] = 'X';
	for (int j = 0; j <= C + 1; j++) board[0][j] = board[R + 1][j] = 'X';

	/*
	printf("%d %d\n", R, C);
	for (int i = 0; i <= R + 1; i++) {
		for (int j = 0; j <= C + 1; j++) {
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
	*/

	// 입력받은 board를 boardInfo로 바꿈
	numCar = numPark = 0;
	for (int i = 0; i <= R + 1; i++) {
		for (int j = 0; j <= C + 1; j++) {
			if (board[i][j] == 'C') {
				carPos[numCar].y = i; carPos[numCar].x = j;
				boardInfo[i][j] = numCar;
				numCar++;
			}
			else if (board[i][j] == 'P') {
				boardInfo[i][j] = MAX_CAR + numPark;
				numPark++;
			}
			else if (board[i][j] == 'X') boardInfo[i][j] = WALL;
			else board[i][j] = BLANK;
		}
	}

	// 각 차에서 각 주차구역까지의 거리 (dist) 계산 
	for (int i = 0; i < numCar; i++) {
		for (int j = 0; j <= R + 1; j++)
			for (int k = 0; k <= C + 1; k++)
				curDist[j][k] = INF;

		q.push(carPos[i]);
		curDist[carPos[i].y][carPos[i].x] = 0;

		while (!q.empty()) {
			POS f = q.front(); q.pop();
			int fy = f.y; int fx = f.x;
			for (int j = 0; j < 4; j++) {
				int cy = fy + dy[j];
				int cx = fx + dx[j];

				if (boardInfo[cy][cx] != WALL && curDist[cy][cx] > curDist[fy][fx] + 1) {
					curDist[cy][cx] = curDist[fy][fx] + 1;
					POS cur;
					cur.y = cy; cur.x = cx;
					q.push(cur);
				}
			}
		}

		for (int j = 0; j <= R + 1; j++) {
			for (int k = 0; k <= C + 1; k++) {
				if (boardInfo[j][k] >= MAX_CAR) {
					dist[i][boardInfo[j][k] - MAX_CAR] = curDist[j][k];
				}
			}
		}
	}

	// 이분 탐색으로 답 확인
	int left = 0, right = INF, ans = INF;
	while (left <= right) {
		int mid = (left + right) / 2;
		initNetwork(mid);
		if (getMaxFlow() >= numCar) { // 모든 차가 mid 시간 이내에 주차 가능
			if (ans > mid) ans = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	if (ans < INF) printf("%d\n", ans);
	else printf("-1\n");
	return 0;
}
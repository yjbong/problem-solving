#include <cstdio>
#include <vector>
#define MAXN 100
using namespace std;

int N; // 도시의 개수
char road[MAXN][MAXN + 1]; // road[i][j] = i번 도시에서 j번 도시로 가는 길이 있으면 Y, 없으면 N

// 위상정렬을 위한 데이터
typedef struct {
	int indegree;
	vector <int> outvertices;
}NODE;

NODE city[MAXN];
bool check[MAXN];

int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%s", road[i]);

	// 위상정렬 데이터 초기화
	for (int i = 0; i < N; i++) {
		city[i].indegree = 0;
		city[i].outvertices.clear();
		check[i] = false;
	}

	// 위상정렬 데이터 만들기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			// i에서 j로 가는 일방통행 도로
			else if (road[i][j] == 'Y' && road[j][i] == 'N') {
				city[i].outvertices.push_back(j);
				city[j].indegree++;
			}
			// j에서 i로 가는 일방통행 도로
			else if (road[i][j] == 'N' && road[j][i] == 'Y'){
				city[j].outvertices.push_back(i);
				city[i].indegree++;
			}
			// 위상정렬에서 양방통행 도로는 고려하지 않는다.
		}
	}

	// 위상정렬 수행
	bool isDAG = true; // 위상정렬이 가능하다면 Directed Acyclic Graph 이다.
	for (int i = 0; i < N; i++) {
		int j;
		for (j = 0; j < N; j++) {
			if (check[j] == false && city[j].indegree == 0) {
				check[j] = true;
				for (int k = 0; k < city[j].outvertices.size(); k++) city[city[j].outvertices[k]].indegree--;
				break;
			}
		}
		if (j == N) { isDAG = false; break; } // 현재 iteration 에서 indegree가 0인 도시를 찾을 수 없다면 위상정렬 불가능
	}

	// 주어진 그래프에서 일방통행 도로만 고려하여 위상정렬이 가능하다면 목적 달성이 가능하다. 왜냐하면,
	// 먼저, 위상정렬이 가능하다면 DAG인 것이므로 양방통행 도로를 고려하기 전에는 사이클이 없는 것이다.
	// 여기에 어떤 도시 a와 b를 잇는 양방통행 도로를 일방통행 도로로 바꿔 추가한다고 하자.
	// 만약 위상정렬에서 a가 b보다 앞에 나왔다면 a->b 방향의 일방통행 도로로 바꾼다. 이렇게 하면 위상정렬 결과는 변하지 않으며 사이클도 생기지 않는다.
	// 반대로 위상정렬에서 b가 a보다 앞에 나왔다면 양방통행 도로를 b->a 방향의 일방통행 도로로 바꾸면 된다.
	if (isDAG) printf("YES\n");
	else printf("NO\n");

	return 0;
}
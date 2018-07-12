#include <cstdio>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#include <functional>
#define MAXN 100000
#define MAXM 100000
using namespace std;
int T; // 테스트 케이스의 개수
int N; // 정점(도미노)의 개수
int M; // 관계의 개수
vector <int> adj[MAXN+1]; // adj[i] = i번 블록이 넘어지면 같이 넘어지는 블록들의 목록
vector <int> adjInv[MAXN + 1]; // adjInv[i] = i번 블록을 넘어지게 하는 블록들의 목록 (inv의 역)

// Kosaraju 알고리즘에 필요한 데이터
int dt[MAXN + 1]; // dt[i] = i번 정점(도미노)을 방문하는 시간 (discovery time)
int ft[MAXN + 1]; // ft[i] = i번 정점의 모든 자식들을 방문하고 이 정점을 빠져나가는 시간 (finish time)

int time; // 현재 시간
bool check[MAXN + 1]; // 방문 여부

set<int>::iterator it;

void setFinishTime(int idx) {
	if (dt[idx] >= 0) return; // 정점의 discovery time이 초기값이 아니라면 이 정점은 이미 방문이 된 것이다.
	dt[idx] = time++;
	for (int i = 0; i < adj[idx].size(); i++) setFinishTime(adj[idx][i]);
	ft[idx] = time++;
}

typedef struct {
	bool inedgeExist; // SCC를 하나의 큰 정점이라고 봤을 때, 이 정점으로 들어오는 edge가 있는지 여부
	set <int> vertexSet; // SCC에 속한 정점 리스트
}SCC;

vector <SCC> sccList;

void dfs(int idx, SCC &curSCC) {
	if (check[idx]) return;
	check[idx] = true;
	curSCC.vertexSet.insert(idx);
	for (int i = 0; i < adjInv[idx].size(); i++) dfs(adjInv[idx][i], curSCC);
}

SCC getSCC(int idx) {

	SCC output;
	output.inedgeExist = false;
	output.vertexSet.clear();

	dfs(idx, output);

	for (it = output.vertexSet.begin(); it != output.vertexSet.end(); it++) {
		int curVertex = *it; // SCC에 속한 한 정점
		for (int i = 0; i < adjInv[curVertex].size(); i++) {
			int preVertex = adjInv[curVertex][i]; // curVertex번 도미노를 쓰러뜨리는 도미노

			// preVertex가 curVertex와 같은 SCC에 속하지 않는다면(SCC에 inedge가 있다면),
			// 이 SCC에 속한 모든 도미노는 직접 건드릴 필요가 없다.
			if (output.vertexSet.find(preVertex) == output.vertexSet.end()) { 
				output.inedgeExist = true;
				goto out;
			}
		}
	}
out:
	return output;
}

void kosaraju(void) {

	vector <pair<int, int> > dfsOrder; // first: FInish Time, second: index
	for (int i = 1; i <= N; i++) dfsOrder.push_back(make_pair(ft[i], i));
	sort(dfsOrder.begin(), dfsOrder.end(), greater<pair<int,int> >());

	for (int i = 1; i <= N; i++) check[i] = false;
	for (int i = 0; i < N; i++) {
		if (!check[dfsOrder[i].second]) {
			sccList.push_back(getSCC(dfsOrder[i].second));
		}
	}
}

int main(void) {

	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &M);
		// 초기화 작업
		sccList.clear();
		for (int i = 1; i <= N; i++) {
			adj[i].clear();
			adjInv[i].clear();
			dt[i] = ft[i] = -1;
		}

		// 관계 입력
		for (int i = 0; i < M; i++) {
			int x, y;
			scanf("%d %d", &x, &y); // x번 블록이 넘어지면 y번 블록도 넘어짐 (반대로는 아님)
			adj[x].push_back(y);
			adjInv[y].push_back(x);
		}

		// 각 정점(도미노)의 discovery time, finish time 계산
		time = 0;
		for (int i = 1; i <= N; i++) {
			if (dt[i] < 0) setFinishTime(i);
		}

		//for (int i = 1; i <= N; i++) printf("vertex %d : dt = %d, ft = %d\n", i, dt[i], ft[i]);
		//printf("\n");

		// Kosaraju 알고리즘 수행
		kosaraju();

		// 답 확인
		int ans = 0;
		for (int i = 0; i < sccList.size(); i++) {
			//printf("sccList %d : ", i);
			//for (it = sccList[i].vertexSet.begin(); it != sccList[i].vertexSet.end(); it++) printf("%d ", *it);
			//printf("\n");

			if (sccList[i].inedgeExist == false) ans++; // 어떤 SCC로 들어오는 inedge가 없다면, SCC에 속하는 도미노 중 1개를 직접 건드려야 한다.
		}
		printf("%d\n", ans);
	}

	return 0;
}
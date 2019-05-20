#include <cstdio>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 200
int N; // 도시의 수
int w[MAX_N][MAX_N]; // w[i][j] = 음수이면 i,j번 도시가 이미 연결된 것이고 양수이면 i,j번 도시 연결 비용

typedef pair<int, int> ii;
typedef pair<int, ii> iii; // first: weight, second: 연결된 두 정점의 번호

vector <iii> edge;
int p[MAX_N]; // p[i] = i번 정점의 parent

// 출력값
int totalCost;
vector <ii> mst;

int find2(int a) { // 정점 a를 포함한 집합의 대표값을 리턴
	while (p[a] >= 0) a = p[a];
	return a;
}

void union2(int a, int b) { // 정점 a가 포함된 집합과 정점 b가 포함된 집합을 합침
	int pa = find2(a);
	int pb = find2(b);

	if (pa == pb) return; // a와 b가 이미 같은 집합에 속해있는 경우 아무것도 하지 않음

	if (p[pa] < p[pb]) p[pb] = pa; // a집합의 높이가 b집합의 높이보다 작으면 a집합을 b집합에 합침
	else if (p[pa] == p[pb]) { // 높이가 같은 경우 b집합을 a집합에 합치는데, 이때 a집합의 높이가 1 증가
		p[pb] = pa;
		p[pa]--;
	}
	else p[pa] = pb; // a집합의 높이가 b집합의 높이보다 작으면 a집합을 b집합에 합침
}

int main(void){
	
	scanf("%d",&N);
	for(int i=0; i<N; i++)
	    for(int j=0; j<N; j++)
	        scanf("%d",&w[i][j]);
	
	// edge 리스트 구성
	for(int i=0; i<N; i++)
		for(int j=i+1; j<N; j++)
	        if(w[i][j]>0) edge.push_back(make_pair(w[i][j], make_pair(i,j)));
	
	// kruskal
	sort(edge.begin(), edge.end());
	totalCost=0;
	for (int i=0; i<N; i++) p[i] = -1; // disjoint set 초기화
	
	for(int i=0; i<N; i++)
	    for(int j=i+1; j<N; j++)
	        if(w[i][j]<0){
	        	union2(i,j); // 기존 연결된 도로
	        	totalCost -= w[i][j]; // 기존 도로는 무조건 비용에 들어감
	        }
	        
	for (int i = 0; i < edge.size(); i++) {
		int cost = edge[i].first;
		int v1 = edge[i].second.first;
		int v2 = edge[i].second.second;
		if (find2(v1) != find2(v2)) {
			totalCost += cost;
			mst.push_back(make_pair(v1, v2));
			union2(v1, v2);
		}
	}

	// 답 출력
	printf("%d %d\n", totalCost, mst.size()); // 총 연결 비용, 최소 신장 트리의 크기
	for(int i=0; i<mst.size(); i++)
	    printf("%d %d\n", mst[i].first+1, mst[i].second+1);

	return 0;
}

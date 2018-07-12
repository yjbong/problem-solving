#include <cstdio>
#include <queue>
#include <algorithm>
#define MAX_N 1000000
using namespace std;
typedef pair<int, int> ii;

int N; // 수열의 길이
int a[MAX_N+1]; // 수열 (인덱스 1부터 시작)

int p[MAX_N+1]; // disjoint set에서 i의 부모 (음수일 경우, 절대값은 트리의 높이)
vector <int> cs[MAX_N+1]; // cs[i] = i번 정점을 루트로 하는 연결 정점 집합

priority_queue <int> pq;
vector <ii> printOrder; // 집합 출력 순서

int find2(int a){ // 정점 a를 포함한 집합의 대표값을 리턴
	while (p[a] >= 0) a = p[a];
	return a;
}

void union2(int a, int b){ // 정점 a가 포함된 집합과 정점 b가 포함된 집합을 합침
	int pa = find2(a);
	int pb = find2(b);

	if (pa == pb) return; // a와 b가 이미 같은 집합에 속해있는 경우 아무것도 하지 않음

	if (p[pa] < p[pb]) p[pb] = pa; // a집합의 높이가 b집합 높이보다 크면 b집합을 a집합에 합침
	else if (p[pa] == p[pb]){ p[pb] = pa; p[pa]--; } // 높이가 같은 경우 b집합을 a집합에 합치는데, 이때 a집합의 높이가 1 증가
	else p[pa] = pb; // a집합의 높이가 b집합의 높이보다 작으면 a집합을 b집합에 함침
}

int main(void){

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &a[i]);
	
	// disjoint set 초기화
	for (int i = 1; i <= N; i++) p[i] = -1;

	// 
	for (int i = 1; i <= N; i++){
		if (!pq.empty() && (pq.top() > a[i]) ){ // a[i]의 왼쪽에 a[i]보다 큰 수가 존재할 때
			int maxNum = pq.top(); // 가장 큰 수는 기억해 놓아야 함
			
			union2(a[i], maxNum);
			pq.pop();

			while (!pq.empty() && (pq.top() > a[i]) ){
				union2(a[i], pq.top());
				pq.pop();
			}

			pq.push(maxNum); // 집합 중에 가장 큰 수를 대표 번호로 써야 함
		}
		else pq.push(a[i]);
	}

	// 집합을 vector에 저장
	for (int i = 1; i <= N; i++){
		int curRoot = find2(a[i]);
		cs[curRoot].push_back(a[i]);
	}

	// 집합 목록을 오름차순 정렬
	for (int i = 1; i <= N; i++)
		if (cs[i].size() > 0) sort(cs[i].begin(), cs[i].end());

	// 집합의 출력 순서 정하기 (집합 원소 중 최소값이 작은 순서대로 출력해야함)
	for (int i = 1; i <= N; i++)
		if (cs[i].size() > 0) printOrder.push_back(make_pair(cs[i][0], i));
	sort(printOrder.begin(), printOrder.end());

	// 답 출력
	printf("%d\n", printOrder.size());
	for (int i = 0; i < printOrder.size(); i++){
		int curIdx = printOrder[i].second;
		printf("%d ", cs[curIdx].size());
		for (int j = 0; j < cs[curIdx].size(); j++) printf("%d ", cs[curIdx][j]);
		printf("\n");
	}

	return 0;
}
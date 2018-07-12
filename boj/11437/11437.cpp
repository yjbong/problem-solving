#include <cstdio>
#include <vector>
#include <queue>
#define MAX_V 50000 // 최대 정점 개수
using namespace std;
int N; // 노드의 개수
int M; // 정점 쌍(쿼리)의 개수

vector <int> adj[MAX_V+1]; // adj[i] = i번 정점과 직접 연결된 정점 목록

int lv[MAX_V+1]; // lv[i] = i번 정점의 레벨 (루트의 레벨은 1)
queue <int> q;
int p[MAX_V+1]; // p[i] = i번 정점의 부모 (루트의 부모는 0)

int main(void){

	scanf("%d",&N);
	for(int i=0; i<N-1; i++){
		int v0,v1; // 연결된 두 정점
		scanf("%d %d",&v0,&v1);
		// 양방향 간선 추가 (v0->v1,v1->v0);
		adj[v0].push_back(v1);
		adj[v1].push_back(v0);
	}

	// 각 정점의 레벨 구하기
	lv[1]=1; // 1번 정점이 루트
	p[1]=0;
	q.push(1);

	while(!q.empty()){
		int f=q.front();
		q.pop();
		for(int i=0; i<adj[f].size(); i++){
			int curv=adj[f][i];
			if(lv[curv]==0){
				lv[curv]=lv[f]+1;
				p[curv]=f;
				q.push(curv);
			}
		}
	}

	// 쿼리 수행
	scanf("%d",&M);
	for(int i=0; i<M; i++){
		int v0,v1; // LCA를 구하고자 하는 두 정점
		scanf("%d %d",&v0,&v1);

		// 두 정점의 레벨을 같게 맞춤
		if(lv[v0]>lv[v1]){
			int diff=lv[v0]-lv[v1];
			for(int j=0; j<diff; j++) v0=p[v0];
		}
		else if(lv[v0]<lv[v1]){
			int diff=lv[v1]-lv[v0];
			for(int j=0; j<diff; j++) v1=p[v1];
		}

		// LCA 탐색
		while(v0!=v1){ v0=p[v0]; v1=p[v1]; }
		printf("%d\n",v0);
	}
	return 0;
}
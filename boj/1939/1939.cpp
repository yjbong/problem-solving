#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#define MAX_N 10000
#define MAX_C 1000000000
using namespace std;
typedef pair<int,int> ii; // first: 목적지, second: 중량제한

int N; // 섬의 수
int M; // 다리의 수
int from,to; // 두 공장의 위치

vector <ii> adj[MAX_N+1]; // adj[i] = i번 정점에 붙어있는 간선의 정보

// movable(weight) = 중량이 weight인 물건을 옮길 수 있는지 확인
bool movable(int weight){
	vector <bool> visited(N+1,false);
	queue <int> q;

	q.push(from);
	visited[from]=true;
	while(!q.empty()){
		int f=q.front(); q.pop();
		if(f==to) return true; // 목적지에 도착할 수 있는 경우
		for(int i=0; i<adj[f].size(); i++){
			if(visited[adj[f][i].first]==false && adj[f][i].second>=weight){ // 다리가 중량을 견딜 수 있는 경우
				q.push(adj[f][i].first);
				visited[adj[f][i].first]=true;		
			}
		}
	}
	return false;
}

int main(void){
	scanf("%d %d",&N,&M);
	for(int i=0; i<M; i++){
		int A,B,C;
		scanf("%d %d %d",&A,&B,&C);
		// 양방향 간선 추가
		adj[A].push_back(make_pair(B,C));
		adj[B].push_back(make_pair(A,C));
	}
	scanf("%d %d",&from,&to);

	// 운송 가능한 최대 무게를 이분 탐색으로 구함
	int left=0, right=MAX_C;
	int ans=0;
	while(left<=right){
		int mid=(left+right)/2;
		if(movable(mid)){
			if(ans<mid) ans=mid;
			left=mid+1;	
		}
		else right=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}
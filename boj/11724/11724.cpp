#include <cstdio>

int N; // 정점의 개수
int M; // 간선의 개수
int a[1001][1001];
bool visited[1001];

void dfs(int idx){
	if(visited[idx]==false){
		visited[idx]=true;
		for(int i=1; i<=N; i++)
			if(a[idx][i]) dfs(i);
	}
}
int main(void){
	scanf("%d %d",&N,&M);
	for(int i=0; i<M; i++){
		int v1,v2;
		scanf("%d %d",&v1,&v2);
		a[v1][v2]=a[v2][v1]=1; // 무방향 간선
	}
	int ans=0;
	for(int i=1; i<=N; i++){
		if(visited[i]==false){
			ans++;
			dfs(i); // i와 연결된 정점들을 모두 방문
		}
	}
	printf("%d\n",ans);
	return 0;
}
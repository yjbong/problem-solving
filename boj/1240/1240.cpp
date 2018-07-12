#include <cstdio>
#include <queue>
#define INF 1000000000
using namespace std;

int n; // node 갯수
int m; // 거리를 알고 싶은 node 쌍의 수
int w[1111][1111]; // w[i][j] = 정점 i에서 j로의 직접 경로가 있으면 그 길이, 아니면 무한대
int lv[1111]; // lv[i] = 정점 i의 레벨
int p[1111]; // p[i] = 정점i의 parent (없으면 -1)

queue <int> q;

int main(void){

	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) w[i][j]=INF;

	// 트리 입력
	for(int i=0; i<n-1; i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		if(w[a][b]>c) w[a][b]=c;
		if(w[b][a]>c) w[b][a]=c;
	}

	for(int i=1; i<=n; i++) lv[i]=INF;
	for(int i=1; i<=n; i++) p[i]=-1;

	// 1번 노드를 루트로 함
	q.push(1);
	lv[1]=0;

	// 루트와의 거리(lv)를 구하기
	while(!q.empty()){
		int f=q.front(); q.pop();
		for(int i=1; i<=n; i++){
			if(w[f][i]<INF && lv[i]>lv[f]+1){
				lv[i]=lv[f]+1;
				p[i]=f;
				q.push(i);
			}
		}
	}

	// 노드 쌍 입력
	for(int i=0; i<m; i++){
		int a,b,ans=0;
		scanf("%d %d",&a,&b);

		// a와 b의 높이를 같게 맞춰줌
		if(lv[a]>lv[b]){
			int cnt=lv[a]-lv[b];
			for(int j=0; j<cnt; j++){
				if(p[a]>=0){
					ans+=w[a][p[a]];
					a=p[a];
				}
			}
		}
		else if(lv[b]>lv[a]){
			int cnt=lv[b]-lv[a];
			for(int j=0; j<cnt; j++){
				if(p[b]>=0){
					ans+=w[b][p[b]];
					b=p[b];
				}
			}
		}

		// a와 b의 공통 조상을 찾을 때까지 거리를 추가
		while(a!=b){
			if(p[a]>=0){
				ans+=w[a][p[a]];
				a=p[a];
			}
			if(p[b]>=0){
				ans+=w[b][p[b]];
				b=p[b];
			}
		}

		printf("%d\n",ans);
	}
	return 0;
}
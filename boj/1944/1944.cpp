#include <cstdio>
#include <utility>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX_N 50
#define MAX_M 250
#define INF 1000000000
using namespace std;
int N; // 미로의 크기
int M; // 열쇠의 개수
char board[MAX_N+2][MAX_N+2]; // 미로
int idxmap[MAX_N+2][MAX_N+2]; // 미로에서 S, K 위치에 대한 idx값 (1부터 시작)

int vertices; // S와 K인 위치의 개수
int dist[MAX_N+2][MAX_N+2]; // dist[i][j] = 현재 기준점에서 (i,j)까지의 거리

const int dy[4]={-1,1,0,0};
const int dx[4]={0,0,1,-1};

vector <pair<int,pair<int,int> > > edgeList; // 간선 리스트 (first: 비용, second.first: 시작 정점, second.second: 끝 정점)

// for disjoint set
int p[MAX_M+2]; // p[i] = i번 정점의 parent
int find2(int a){
	while(p[a]>=0) a=p[a];
	return a;
}
void union2(int a, int b){
	int pa=find2(a);
	int pb=find2(b);
	if(pa==pb) return;
	else if(p[pa]<p[pb]){ // a집합의 높이가 b집합의 높이보다 높음
		p[pb]=pa;
	}
	else if(p[pa]>p[pb]){ // b집합의 높이가 a집합의 높이보다 높음
		p[pa]=pb;
	}
	else{ // 높이가 같음 (b집합을 a집합에 합치기로 정함)
		p[pb]=pa;
		p[pa]--; // a집합의 높이 증가
	}
}

// 기준점이 sy,sx일 때의 dist배열 계산
void calcDist(int sy, int sx){
	// BFS
	queue <pair<int,int> > q;
	for(int i=0; i<=N+1; i++)
		for(int j=0; j<=N+1; j++) dist[i][j]=INF;

	q.push(make_pair(sy,sx));
	dist[sy][sx]=0;
	while(!q.empty()){
		pair <int,int> f=q.front();
		int fy=f.first, fx=f.second;
		q.pop();
		for(int i=0; i<4; i++){
			int cy=fy+dy[i];
			int cx=fx+dx[i];

			// 이동 가능하고, fy,fx를 거쳐 cy,cx로 도달하는 것이 더 짧은 경우
			if(board[cy][cx]!='1' && dist[cy][cx]>dist[fy][fx]+1){
				dist[cy][cx]=dist[fy][fx]+1;
				q.push(make_pair(cy,cx));
			}
		}
	}
}

void addEdge(int idx){
	for(int i=0; i<=N+1; i++){
		for(int j=0; j<=N+1; j++){
			if(idxmap[i][j]!=0 && idxmap[i][j]!=idx){
				if(dist[i][j]<INF){ // 도달 가능한 경우
					edgeList.push_back(make_pair(dist[i][j], make_pair(idx,idxmap[i][j]) ) );
				}
			}
		}
	}
}

int main(void){
	scanf("%d %d\n",&N,&M);
	for(int i=1; i<=N; i++) gets(board[i]+1);
	for(int i=0; i<=N+1; i++) board[i][0]=board[i][N+1]='1';
	for(int j=0; j<=N+1; j++) board[0][j]=board[N+1][j]='1';

	vertices=0;
	for(int i=0; i<=N+1; i++)
		for(int j=0; j<=N+1; j++)
			if(board[i][j]=='S' || board[i][j]=='K') idxmap[i][j]=(++vertices);

	for(int i=0; i<=N+1; i++){
		for(int j=0; j<=N+1; j++){
			if(board[i][j]=='S' || board[i][j]=='K'){
				calcDist(i,j); // i,j를 기준점으로 하여 모든 위치와의 최단 거리 계산
				int curIdx=idxmap[i][j];
				addEdge(curIdx); // i,j를 시작점으로 하는 모든 edge를 edgeList에 추가
			}
		}
	}

	sort(edgeList.begin(), edgeList.end()); // edge를 비용 순으로 오름차순 정렬

	// disjoint set init
	for(int i=1; i<=vertices; i++) p[i]=-1;

	// kruskal 실행
	int ans=0;
	for(int i=0; i<edgeList.size(); i++){
		int cost=edgeList[i].first;
		int from=edgeList[i].second.first;
		int to=edgeList[i].second.second;

		// from과 to가 이미 연결되어 있는 경우 무시한다.
		if(find2(from)==find2(to)) continue;

		// 그렇지 않은 경우 from과 to를 연결하고 그 비용을 추가한다.
		union2(from,to);
		ans+=cost;
	}

	// 모든 정점이 연결되었는지 검사
	int sets=0;
	for(int i=1; i<=vertices; i++) if(p[i]<0) sets++;

	if(sets>1) printf("-1\n"); // disjoint set이 2개 이상인 경우, 연결되지 않은 정점이 있는 것이다.
	else printf("%d\n",ans);
	
	return 0;
}
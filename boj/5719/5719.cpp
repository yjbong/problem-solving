#include <cstdio>
#include <set>
#include <queue>
#include <utility>
#include <vector>
#define MAX_N 500
#define MAX_M 10000
#define INF 1000000000
using namespace std;
int N; // 장소의 수
int M; // 도로의 수
int S, D; // 시작점, 도착점
typedef pair<int, int> ii;
 
vector<ii> adj[MAX_N]; // adj[i] = 출발점이 i번 장소인 간선들 (first: to, second: cost)
 
set<ii> fastEdge; // 최단경로에 포함되는 간선 (first: from, second: to)
 
int dist[MAX_N]; // dist[i] = 시작점에서부터 i번 장소까지의 최단 거리
 
vector <int> pre[MAX_N]; // pre[i] = 시작점에서 i번 장소까지 최단 거리로 갈 때 직전에 지나는 장소들
 
int dijkstra(void){
    priority_queue<ii> pq; // first : -dist[i], second: i
    for(int i=0; i<N; i++){
        dist[i]=INF;
        pre[i].clear();
    }
    dist[S]=0;
    pq.push(make_pair(-dist[S], S));
    while(!pq.empty()){
        int f=pq.top().second; pq.pop();
        for(int i=0; i<adj[f].size(); i++){
            int to=adj[f][i].first;
            int cost=adj[f][i].second;
            if(dist[to]>dist[f]+cost){
                dist[to]=dist[f]+cost;
                pq.push(make_pair(-dist[to], to));
                pre[to].clear();
                pre[to].push_back(f);
            }
            else if(dist[to]==dist[f]+cost)
                pre[to].push_back(f);
        }
    }
    return dist[D];
}
 
bool visited[MAX_N];
void dfs(int idx){
    if(visited[idx]) return;
    visited[idx]=true;
    for(int i=0; i<pre[idx].size(); i++){
        fastEdge.insert(make_pair(pre[idx][i], idx));
        dfs(pre[idx][i]);
    }
}
 
int main() {
 
    while(1){
        // 초기화
        for(int i=0; i<N; i++){
            adj[i].clear();
            visited[i]=false;
        }
        fastEdge.clear();
 
        // 입력
        scanf("%d %d",&N,&M);
        if(N==0 && M==0) break;
        scanf("%d %d",&S,&D);
        for(int i=0; i<M; i++){
            int U, V, P;
            // U->V 로 비용 P만큼으로 이동
            scanf("%d %d %d",&U,&V,&P);
            adj[U].push_back(make_pair(V, P));
        }
 
        // 원본 그래프에서 dijkstra 수행
        dijkstra();
 
        // fastEdge(최단 경로에 포함되는 edge) 찾기
        dfs(D);
 
        // fastEdge를 제외한 간선 리스트 구성
        for(int i=0; i<N; i++){
            vector <ii> tmp;
            tmp.clear();
            for(int j=0; j<adj[i].size(); j++)
                if(fastEdge.find(make_pair(i, adj[i][j].first))==fastEdge.end()) tmp.push_back(adj[i][j]);
            adj[i].clear();
            adj[i]=tmp;
        }
 
        // fastEdge를 제외하고 dijkstra 수행
        int ans=dijkstra();
        if(ans<INF) printf("%d\n", ans);
        else printf("-1\n");
    }
    return 0;
}
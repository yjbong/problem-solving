#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
#define INF 1000000000
#define MAX_N 5000
using namespace std;
typedef pair<int,int> ii;
int N; // 도시의 수(=택시회사의 수)
int K; // 도로의 수
ii T[MAX_N+1]; // T[i] = (i번 도시에서 출발하는 택시의 요금, 택시가 갈 수 있는 도로의 최대 개수)
vector<int> adj[MAX_N+1]; // adj[i] = (입력으로 주어진) i번 도시와 직접 연결된 도시들의 리스트
int dist[MAX_N+1][MAX_N+1]; // dist[i][j] = i번 도시에서 j번 도시까지 가기 위해 지나야 하는 도로의 개수
queue<int> q;

int cost[MAX_N+1]; // cost[i] = 1번 도시에서 i번 도시까지 택시로 이동하기 위한 최소 비용
priority_queue<ii> pq; // (first, second) = (-cost[i], i)

int main(void){
    scanf("%d %d",&N,&K);
    for(int i=1; i<=N; i++)
        scanf("%d %d",&T[i].first,&T[i].second);
    for(int i=0; i<K; i++){
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        // 양방향 도로임
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    
    for(int i=1; i<=N; i++){
        // i번 도시로부터 다른 도시들까지의 dist 계산
        for(int j=1; j<=N; j++) dist[i][j]=INF;
        while(!q.empty()) q.pop();
        dist[i][i]=0;
        q.push(i);
        while(!q.empty()){
            int f=q.front(); q.pop();
            // q에 추가할 도시가 있는지 확인
            if(dist[i][f]>=T[i].second) continue;
            int adjSize=adj[f].size();
            for(int j=0; j<adjSize; j++){
                int c=adj[f][j];
                if(dist[i][c]>dist[i][f]+1){
                    dist[i][c]=dist[i][f]+1;
                    q.push(c);
                }
            }
        }
    }

    // dijkstra
    for(int i=1; i<=N; i++) cost[i]=INF;
    cost[1]=0;
    pq.push(make_pair(-cost[1],1));
    while(!pq.empty()){
        ii f=pq.top(); pq.pop();
        int fcost=-f.first;
        int fcity=f.second;
        for(int i=1; i<=N; i++){
            if(dist[fcity][i]>T[fcity].second) continue; // i번 도시가 fcity에서 택시로 갈 수 있는 도로의 수를 넘어가는 도시인 경우에는 패스
            int fare=T[fcity].first;
            if(cost[i]>cost[fcity]+fare){
                cost[i]=cost[fcity]+fare;
                pq.push(make_pair(-cost[i],i));
            }
        }
    }
    printf("%d\n",cost[N]);
    return 0;
}
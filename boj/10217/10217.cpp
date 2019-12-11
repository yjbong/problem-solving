#include <cstdio>
#include <queue>
#include <utility>
#define MAX_N 100
#define MAX_M 10000
#define INF 1000000000
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
int T; // TC 개수
int N; // 공항의 수
int M; // 총 지원비용
int K; // 티켓정보의 수
 
int D[MAX_N+1][MAX_M+1]; // D[i][j]=i번 공항까지 비용 j를 써서 도달하는 경우에 가능한 최단 거리
vector<iii> adj[MAX_N+1]; // adj[i]=i번 공항을 출발하는 노선 정보(first: 도착 공항, second.first: 비용, second.second: 거리)
 
priority_queue<iii> pq; // first: -D[i][j], second.first: i, second.second: j
int main() {
    scanf("%d",&T);
    while(T--){
        scanf("%d %d %d",&N,&M,&K);
        for(int i=1; i<=N; i++){
            adj[i].clear();
            for(int j=0; j<=M; j++) D[i][j]=INF;
        }
        for(int i=0; i<K; i++){
            int u; // 출발 공항
            int v; // 도착 공항
            int c; // 비용
            int d; // 거리
            scanf("%d %d %d %d",&u,&v,&c,&d);
            adj[u].push_back(make_pair(v,make_pair(c,d)));
        }
 
        // 시작은 1번 공항
        D[1][0]=0;
        pq.push(make_pair(0,make_pair(1,0)));
        while(!pq.empty()){
            iii f=pq.top(); pq.pop();
            int fd=-f.first;
            int fpos=f.second.first;
            int fcost=f.second.second;
            for(int i=0; i<adj[fpos].size(); i++){
                int cpos=adj[fpos][i].first;
                int ccost=fcost+adj[fpos][i].second.first;
                int dist=adj[fpos][i].second.second;
                if(ccost<=M && D[cpos][ccost]>fd+dist){
                    D[cpos][ccost]=fd+dist;
                    pq.push(make_pair(-D[cpos][ccost],make_pair(cpos,ccost)));
                }
            }
        }
 
        // 도착은 N번 공항
        int ans=INF;
        for(int i=0; i<=M; i++) if(ans>D[N][i]) ans=D[N][i];
        if(ans<INF) printf("%d\n",ans);
        else printf("Poor KCM\n");
    }
    return 0;
}
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#define MAX_N 1000000
#define INF 1000000000
using namespace std;
int N; // 정점 개수
vector <int> adj[MAX_N+1]; // adj[i] = i번 정점과 연결된 정점들
int dist[MAX_N+1]; // dist[i] = 루트 정점에서 i번 정점까지의 거리
queue <int> q;
 
int parent[MAX_N+1]; // i번의 부모 정점 (음수면 부모 없음)
vector <int> children[MAX_N+1]; // i번의 자식 정점들
 
int D[MAX_N+1][2];
// D[i][0] = i번 정점을 루트로 하는 트리에서, i번 정점은 얼리 어답터가 아님. 그리고 이 트리에 속한 모든 정점이 문제의 조건인 1) 자신이 얼리 어답터이거나, 2) 자신과 직접 연결된 모든 정점이 얼리 어답터인 것을 만족할 때, 필요한 최소 얼리 어답터의 수
// D[i][1] = i번 정점이 얼리 어답터라는 점만 다르고 나머지 조건은 D[i][0]과 같음
int min2(int a, int b){ return a<b?a:b; }
int solve(int idx, int isEarly){
    if(D[idx][isEarly]>=0) return D[idx][isEarly];
    int ans=isEarly?1:0;
    for(int i=0; i<children[idx].size(); i++){
        int c=children[idx][i];
        if(isEarly) ans+=min2(solve(c,0), solve(c,1));
        else ans+=solve(c,1);
    }
    return D[idx][isEarly]=ans;
}
int main() {
 
    //// 입력
    scanf("%d", &N);
    for(int i=0; i<N-1; i++){
        int u,v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    //// 트리 구성
    for(int i=1; i<=N; i++) dist[i]=INF;
    // 1번 정점을 루트로 함 (아무 정점이나 루트가 될 수 있음)
    dist[1]=0; q.push(1);
    while(!q.empty()){
        int f=q.front(); q.pop();
        for(int i=0; i<adj[f].size();  i++){
            int c=adj[f][i];
            if(dist[c]>dist[f]+1){
                dist[c]=dist[f]+1;
                q.push(c);
            }
        }
    }
 
    for(int i=1; i<=N; i++){
        parent[i]=-1;
        for(int j=0; j<adj[i].size();  j++){
            int c=adj[i][j];
            if(dist[c]<dist[i]) parent[i]=c;
            else children[i].push_back(c);
        }
    }
 
    // 답 계산
    for(int i=1; i<=N; i++)
        D[i][0]=D[i][1]=-1; // 음수: 미정
 
    // Top-down DP
    int ans=min2(solve(1,0),solve(1,1));
    printf("%d\n",ans);
    return 0;
}
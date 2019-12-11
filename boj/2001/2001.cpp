#include <cstdio>
#include <vector>
#include <queue>
#define MAX_N 100
#define MAX_M 1000
#define MAX_K 14

using namespace std;
typedef pair<int,int> ii;
int N; // 섬의 수
int M; // 다리의 수
int K; // 보석의 수
int D[MAX_N+1][1<<MAX_K]; // D[i][j]=i번 섬에 있고, 보석을 주운 상태가 j인 경우가 가능하다면 1, 아니면 0

int jewel2island[MAX_K]; // jewel2island[i] = i번 보석이 있는 섬의 번호
int island2jewel[MAX_N+1]; // island2jewel[i] = i번 섬에 있는 보석의 번호(없으면 음수)

int jewels[1<<MAX_K]; // jewels[i]=상태 i가 갖는 보석의 수

vector<ii> adj[MAX_N+1]; // i번 섬에서 출발하는 다리 (first: 도착 섬, second: 다리가 견딜 수 있는 보석의 수)

queue<ii> q;

int main() {
    scanf("%d %d %d",&N,&M,&K);
    for(int i=1; i<=N; i++) island2jewel[i]=-1;
    for(int i=0; i<(1<<K); i++)
        for(int j=0; j<K; j++) jewels[i]+=(i&(1<<j))?1:0;

    for(int i=0; i<K; i++){
        int idx;
        scanf("%d",&idx);
        jewel2island[i]=idx;
        island2jewel[idx]=i;
    }
    for(int i=0; i<M; i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        // 다리는 양방향 통행 가능
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
    }

    // BFS
    D[1][0]=1;
    q.push(make_pair(1,0));
    if(island2jewel[1]>=0){
        D[1][1<<island2jewel[1]]=1;
        q.push(make_pair(1,1<<island2jewel[1]));
    }
    while(!q.empty()){
        ii f=q.front(); q.pop();
        int fidx=f.first;
        int fstat=f.second;
        for(int i=0; i<adj[fidx].size(); i++){
            int cidx=adj[fidx][i].first;
            int limit=adj[fidx][i].second;
            if(limit<jewels[fstat]) continue; // 다리가 못 버티면 패스

            if(!D[cidx][fstat]){
                D[cidx][fstat]=1;
                q.push(make_pair(cidx,fstat));
            }
            if(island2jewel[cidx]>=0 && !D[cidx][fstat|(1<<island2jewel[cidx])]){
                D[cidx][fstat|(1<<island2jewel[cidx])]=1;
                q.push(make_pair(cidx,fstat|(1<<island2jewel[cidx])));
            }
        }
    }

    // 답 확인
    int ans=0;
    for(int i=0; i<(1<<K); i++){
        if(D[1][i] && ans<jewels[i]) ans=jewels[i];
    }
    printf("%d\n",ans);
    return 0;
}
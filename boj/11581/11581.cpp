#include <cstdio>
#include <vector>
#define MAX_N 100
using namespace std;
int N; // 교차로의 수 (1~N)
vector <int> adj[MAX_N]; // adj[i] = i번 교차로와 연결된 교차로
bool visited[MAX_N+1];
bool isCycle;
 
void go(int idx){
    if(isCycle) return;
    if(idx==N) return;
    for(int i=0; i<adj[idx].size(); i++){
        int nxt=adj[idx][i];
        if(!visited[nxt]){
            visited[nxt]=true;
            go(nxt);
            visited[nxt]=false;
        }
        else isCycle=true;
    }
}
 
int main() {
    scanf("%d",&N);
    for(int i=1; i<N; i++){
        int adjs;
        scanf("%d",&adjs);
        for(int j=0; j<adjs; j++){
            int c;
            scanf("%d",&c);
            adj[i].push_back(c);
        }
    }
 
    // 1번 교차로에서 시작하는 경로를 모두 탐색하면서 cycle 체크
    isCycle=false;
    visited[1]=true;
    go(1);
    visited[1]=false;
    if(isCycle) printf("CYCLE\n");
    else printf("NO CYCLE\n");
 
    return 0;
}
#include <cstdio>
#include <utility>
#include <queue>
#define MAXN 100
using namespace std;
typedef pair<int,int> ii;
 
int T; // 테스트 케이스
int N; // 편의점의 수
ii P[MAXN+2]; // P[0]: 집의 위치, P[1~N]: 각 편의점 위치, P[N+1]: 공연장 위치
bool visited[MAXN+2];
queue <int> q;
int abs2(int n){ return n>0?n:(-n); }
int main() {
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(int i=0; i<N+2; i++){
            scanf("%d %d",&P[i].first,&P[i].second);
            visited[i]=false;
        }
 
        q.push(0); visited[0]=true;
        while(!q.empty()){
            int f=q.front(); q.pop();
            int fy=P[f].first, fx=P[f].second;
            for(int i=0; i<N+2; i++){
                if(visited[i]) continue;
                int cy=P[i].first, cx=P[i].second;
                if(abs2(fy-cy)+abs2(fx-cx)<=1000){
                    q.push(i); visited[i]=true;
                }
            }
        }
        if(visited[N+1]) printf("happy\n");
        else printf("sad\n");
    }
    return 0;
}
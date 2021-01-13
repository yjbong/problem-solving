#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#define MAXN 50
#define MAXM 13
using namespace std;
typedef pair<int,int> ii;
const int dy[4]={-1,1,0,0};
const int dx[4]={0,0,1,-1};
int N; // 도시의 크기
int M; // 남길 치킨집의 개수
int city[MAXN][MAXN];
int dist[MAXN][MAXN]; // city[i][j]의 치킨거리
vector <ii> home; // 전체 집의 위치
vector <ii> ckn; // 전체 치킨집의 위치
int pick[MAXM];

queue <ii> q;
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> city[i][j];
            if(city[i][j]==1) home.push_back(make_pair(i,j));
            else if(city[i][j]==2) ckn.push_back(make_pair(i,j));
        }
    }
    int totCkns=ckn.size();
    for(int i=totCkns-1; i>=0; i--){
        if(i>=totCkns-M) pick[i]=1;
        else pick[i]=0;
    }

    int ans=1000000000;
    do{
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++) dist[i][j]=1000000000;
        for(int i=0; i<totCkns; i++){
            if(pick[i]){
                dist[ckn[i].first][ckn[i].second]=0;
                q.push(make_pair(ckn[i].first,ckn[i].second));
            }
        }
        while(!q.empty()){
            ii f=q.front(); q.pop();
            int fy=f.first, fx=f.second;
            for(int k=0; k<4; k++){
                int cy=fy+dy[k], cx=fx+dx[k];
                if(cy<0 || cy>=N || cx<0 || cx>=N) continue;
                if(dist[cy][cx]>dist[fy][fx]+1){
                    dist[cy][cx]=dist[fy][fx]+1;
                    q.push(make_pair(cy,cx));
                }
            }
        }
        int curAns=0;
        for(int i=0; i<home.size(); i++)
            curAns+=dist[home[i].first][home[i].second];
        if(ans>curAns) ans=curAns;
    }while(next_permutation(pick,pick+totCkns));

    cout << ans << "\n";
    return 0;
}
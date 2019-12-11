#include <iostream>
#include <queue>
#include <vector>
#include <cassert>
#define MAX_R 100
#define MAX_C 100
using namespace std;
typedef pair<int,int> ii;

int R,C; // 동굴의 크기
int N;
char cave[MAX_R][MAX_C+1];
bool visited[MAX_R][MAX_C];
const int dy[4]={-1,1,0,0};
const int dx[4]={0,0,1,-1};
vector<ii> cluster;
queue<ii> q;

int main() {
    cin >> R >> C;
    cin.get();
    for(int i=0; i<R; i++) cin.getline(cave[i], MAX_C+1);
    //for(int i=0; i<R; i++) cout << cave[i] << endl;
    cin >> N;
    for(int i=0; i<N; i++){
        int S;
        cin >> S; // 막대기를 던지는 높이 (높이 S --> R-S행)
        //cout << S << " ";

        // 막대기를 던져서 미네랄 1개를 깸
        if(i%2==0){ // 왼쪽에서 던짐
            for(int j=0; j<C; j++)
                if(cave[R-S][j]=='x'){ cave[R-S][j]='.'; break; }
        }
        else{ // 오른쪽에서 던짐
            for(int j=C-1; j>=0; j--)
                if(cave[R-S][j]=='x'){ cave[R-S][j]='.'; break; }
        }

        // 클러스터링
        for(int j=0; j<R; j++)
            for(int k=0; k<C; k++) visited[j][k]=false;
        while(!q.empty()) q.pop();
        cluster.clear();

        for(int j=0; j<R; j++){
            for(int k=0; k<C; k++){
                if(!visited[j][k] && cave[j][k]=='x'){
                    visited[j][k]=true;
                    cluster.push_back(make_pair(j,k));
                    q.push(make_pair(j,k));
                    while(!q.empty()){
                        ii f=q.front(); q.pop();
                        int fy=f.first, fx=f.second;
                        for(int l=0; l<4; l++){
                            int cy=fy+dy[l], cx=fx+dx[l];
                            if(cy<0 || cy>=R || cx<0 || cx>=C) continue;
                            if(!visited[cy][cx] && cave[cy][cx]=='x'){
                                visited[cy][cx]=true;
                                cluster.push_back(make_pair(cy,cx));
                                q.push(make_pair(cy,cx));
                            }
                        }
                    }

                    // 현재 클러스터가 공중에 떠 있는지 확인
                    bool onTheSky=true;
                    for(int l=0; l<cluster.size(); l++)
                        if(cluster[l].first==R-1){ onTheSky=false; break; }
                    if(!onTheSky) cluster.clear();
                    else goto out;
                }
            }
        }

out:
        if(cluster.size()>0){ // 뜬 클러스터가 있는 경우
            // 뜬 클러스터는 다른 기호로 표시
            for(int j=0; j<cluster.size(); j++)
                cave[cluster[j].first][cluster[j].second]='#';
            int needDown=-1;
            for(int j=0; j<cluster.size(); j++){
                bool isValid=true;
                int curNeedDown=0;
                int t=cluster[j].first;
                while(t<R-1){
                    if(cave[t+1][cluster[j].second]=='.'){
                        curNeedDown++; t++;
                    }
                    else if(cave[t+1][cluster[j].second]=='#'){
                        isValid=false; break;
                    }
                    else break;
                }
                if(isValid){
                    if(needDown<0 || needDown>curNeedDown)
                        needDown=curNeedDown;
                }
            }
            for(int j=0; j<cluster.size(); j++)
                cave[cluster[j].first][cluster[j].second]='.';
            for(int j=0; j<cluster.size(); j++)
                cave[cluster[j].first+needDown][cluster[j].second]='x';
        }
    }

    for(int i=0; i<R; i++) cout << cave[i] << endl;
    return 0;
}
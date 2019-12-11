#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>
#define MAX_N 125
#define INF 1000000000
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
int N; // 동굴의 크기
int A[MAX_N][MAX_N]; // A[i][j] = (i,j)에 있는 도둑루피의 개수
int D[MAX_N][MAX_N]; // D[i][j] = (0,0)에서 (i,j)까지 이동할 때 얻게 되는 도둑루피의 최소 개수
priority_queue <iii> pq;
const int dy[4]={-1,1,0,0};
const int dx[4]={0,0,1,-1};
int main() {
    int T=1;
    while(1){
        cin >> N;
        if(!N) break;
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++) cin >> A[i][j];

        // Dijkstra
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++) D[i][j]=INF;
        D[0][0]=A[0][0];
        pq.push(make_pair(-D[0][0],make_pair(0,0)));
        while(!pq.empty()){
            iii f=pq.top(); pq.pop();
            int fd=-f.first;
            int fy=f.second.first, fx=f.second.second;
            for(int i=0; i<4; i++){
                int cy=fy+dy[i], cx=fx+dx[i];
                if(cy<0 || cy>=N || cx<0 || cx>=N) continue;
                if(D[cy][cx]>fd+A[cy][cx]){
                    D[cy][cx]=fd+A[cy][cx];
                    pq.push(make_pair(-D[cy][cx],make_pair(cy,cx)));
                }
            }
        }

        printf("Problem %d: %d\n",T,D[N-1][N-1]);
        T++;
    }
    return 0;
}
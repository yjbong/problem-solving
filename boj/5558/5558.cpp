#include <cstdio>
#include <cstdlib>
#include <queue>
#include <utility>
#define INF 1000000000
#define MAX_H 1000
#define MAX_W 1000
#define MAX_N 9
using namespace std;
typedef pair<int,int> ii;
int H; // 맵의 높이
int W; // 맵의 폭
int N; // 치즈의 수

char board[MAX_H+2][MAX_W+2];
ii pos[MAX_N+1]; // 시작점, 1번 치즈 위치, ... , N번 치즈 위치 (y,x)

int dist[MAX_H+2][MAX_W+2]; // dist[i][j] = 기준 위치에서 (i,j)까지의 거리
const int dy[4]={-1,1,0,0};
const int dx[4]={0,0,1,-1};

// 기준 위치가 (y,x)일 때 dist 배열을 계산
void fillDist(int y, int x){
	// dist 초기화
	for(int i=0; i<=H+1; i++)
		for(int j=0; j<=W+1; j++)
			dist[i][j]=INF;

	queue <ii> q;
	dist[y][x]=0;
	q.push(make_pair(y,x));

	while(!q.empty()){
		ii f=q.front(); q.pop();
		int fy=f.first;
		int fx=f.second;
		for(int i=0; i<4; i++){
			int cy=fy+dy[i];
			int cx=fx+dx[i];
			if(board[cy][cx]!='X' && dist[cy][cx]>dist[fy][fx]+1){
				dist[cy][cx]=dist[fy][fx]+1;
				q.push(make_pair(cy,cx));
			}	
		}
	}
}

int main(void){
	scanf("%d %d %d\n",&H,&W,&N);
	for(int i=1; i<=H; i++) gets(board[i]+1);
	for(int i=0; i<=H+1; i++) board[i][0]=board[i][W+1]='X';
	for(int j=0; j<=W+1; j++) board[0][j]=board[H+1][j]='X';

	for(int i=0; i<=H+1; i++){
		for(int j=0; j<=W+1; j++){
			if(board[i][j]=='S'){
				pos[0].first=i; pos[0].second=j;
			}
			else if(board[i][j]>='1' && board[i][j]<='9'){
				pos[board[i][j]-'0'].first=i; pos[board[i][j]-'0'].second=j;
			}
		}
	}

	int ans=0;
	for(int i=0; i<=N-1; i++){
		fillDist(pos[i].first, pos[i].second);
		ans+=dist[pos[i+1].first][pos[i+1].second]; // 다음 치즈까지 가는 거리를 더해줌
	}
	printf("%d\n",ans);

	return 0;
}
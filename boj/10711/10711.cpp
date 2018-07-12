#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int,pair<int,int> > iii; // first = 무너진 시각, second.first = 무너진 곳의 y좌표, second.second = 무너진 곳의 x좌표
typedef pair<int,int> ii; // first = y좌표, second = x좌표

int h; // 격자 세로 크기
int w; // 격자 가로 크기

char board[1001][1001];
const int dy[8]={-1,-1,-1,0,0,1,1,1};
const int dx[8]={-1,0,1,-1,1,-1,0,1};

queue <iii> q;
vector <ii> destroyList; // 현재 시각에 무너지는 곳의 좌표 목록
bool visited[1001][1001];

bool destroy(int y, int x){

	if(!(y>=0 && y<h && x>=0 && x<w)) return false; // 범위 벗어난 곳
	else if(board[y][x]=='.') return false; // 이미 없어진 곳

	int emptyCells=0;
	for(int i=0; i<8; i++){
		int cy=y+dy[i];
		int cx=x+dx[i];
		if(cy>=0 && cy<h && cx>=0 && cx<w && board[cy][cx]=='.') emptyCells++;
	}

	if(emptyCells>=board[y][x]-'0') return true;
	else return false;
}

int main(void){

	scanf("%d %d",&h,&w);
	for(int i=0; i<h; i++) scanf("%s",gets(board[i]));

	int ans=0;

	// 큐 초기화
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			if(destroy(i,j)){
				q.push(make_pair(1, make_pair(i,j)));
				visited[i][j]=true;
				destroyList.push_back(make_pair(i,j));
			}
		}
	}
	
	while(!q.empty()){
		iii f=q.front();
		int ft=f.first; // 현재 좌표 주변(8방향)을 고려할 때의 시각
		int fy=f.second.first; // 현재 y좌표
		int fx=f.second.second; // 현재 x좌표
		q.pop();

		// 바로 이전에 고려한 시각이 x-1이고, 지금 고려하는 시각은 x라면 시각 x-1이 지났을 때 없어지는 모래 좌표 반영
		if(ans<ft){
			for(int i=0; i<destroyList.size(); i++){
				int cy=destroyList[i].first;
				int cx=destroyList[i].second;
				board[cy][cx]='.';
			}
			destroyList.clear();

			ans=ft; // ans 업데이트
		}

		// 현재 좌표 주변 8방향에서 새로 사라지는 좌표 확인
		for(int i=0; i<8; i++){
			int ct=ft+1;
			int cy=fy+dy[i];
			int cx=fx+dx[i];
			if(!visited[cy][cx] && destroy(cy,cx)){
				q.push(make_pair(ct, make_pair(cy,cx)));
				visited[cy][cx]=true;
				destroyList.push_back(make_pair(cy,cx));
			}
		}
	}

	printf("%d\n",ans);
	
	return 0;
}
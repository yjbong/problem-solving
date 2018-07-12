#include <cstdio>
#include <cstdlib>
#include <queue>
#include <utility>
#define INF 1000000000
using namespace std;
typedef pair<int,int> ii;

int cases; // 테스트 케이스 수 
int w; // 지도의 가로 크기 
int h; // 지도의 세로 크기 

char input[1111][1111];
int board[1111][1111]; // board[i][j] : k>=0일 경우  k초 후에 불이 번지는 곳
					   //             : k=-1 이면 벽(이동 불가)
					   //			  : k=INF 이면 아직 확인이 안된 위치
					   // 				(번지는 위치 확인 후에도 그대로 INF로
					   //				남아 있다면 절대 불이 안 붙는 위치)
					    
int d[1111][1111]; // d[i][j] : 좌표 (i,j)에 도달할 수 있는 최단 시간

const int dy[4]={1,-1,0,0};
const int dx[4]={0,0,-1,1};
queue <ii> q; // first : y좌표, second : x좌표 

bool isValid(int y, int x){ // 범위 체크 
	if(y<0 || y>=h || x<0 || x>=w) return false;
	else return true;
}

int main(void){

	scanf("%d",&cases);
	
	while(cases--){
		scanf("%d %d\n",&w,&h);
		for(int i=0; i<h; i++) gets(input[i]);
		
		// board 배열 세팅 
		for(int i=0; i<h; i++)
			for(int j=0; j<w; j++) board[i][j]=INF; // 미확인 위치로 초기화
		
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				if(input[i][j]=='#') board[i][j]=-1; // 벽 
				else if(input[i][j]=='*'){
					board[i][j]=0; // 발화 지점(0초에 불이 붙음) 
					q.push(make_pair(i,j)); // queue에 push (BFS 시작점)				
				}
			}
		}
		
		// board 배열 업데이트 (발화지점으로부터 추가로 불이 옮겨붙는 곳 확인)
		while(!q.empty()){	
			ii f=q.front();
			q.pop();
			int fy=f.first, fx=f.second;
			for(int i=0; i<4; i++){
				int cy=fy+dy[i], cx=fx+dx[i];
				if(isValid(cy, cx)) {
					if(board[cy][cx]>board[fy][fx]+1){
						board[cy][cx]=board[fy][fx]+1; // 불이 옮겨붙음 
						q.push(make_pair(cy,cx));
					}
				}
			}
		}
		
		// d 배열 초기화 
		for(int i=0; i<h; i++)
			for(int j=0; j<w; j++) d[i][j]=INF;
		for(int i=0; i<h; i++)
			for(int j=0; j<w; j++)
				if(input[i][j]=='@'){
					d[i][j]=0;
					q.push(make_pair(i,j)); // queue에 push (BFS 시작점)
				}
				
		// d 배열 업데이트 (각 지점까지 도달하는 최단 시간)
		while(!q.empty()){
			ii f=q.front();
			q.pop();
			int fy=f.first, fx=f.second;
			for(int i=0; i<4; i++){
				int cy=fy+dy[i], cx=fx+dx[i];
				
				// 벽이 아니며, 이동하려는 시점(d[fy][fx]+1)에 불이 안 붙어 있어야 이동 가능 
				if(isValid(cy, cx) && board[cy][cx]>d[fy][fx]+1) {
					if(d[cy][cx]>d[fy][fx]+1){ // (cy,cx)로 가기 위해 현재 (fy,fx)를 거쳐서 가는 것이 더 빠른 경우 
						d[cy][cx]=d[fy][fx]+1;
						q.push(make_pair(cy,cx));
					}
				}
			}
		}

		// 답 구하기 (변에 위치한 d 값들을 확인) 
		int ans=INF; 
		for(int i=0; i<h; i++){
			if(ans>d[i][0]+1) ans=d[i][0]+1;
			if(ans>d[i][w-1]+1) ans=d[i][w-1]+1;
		}
		for(int i=0; i<w; i++){
			if(ans>d[0][i]+1) ans=d[0][i]+1;
			if(ans>d[h-1][i]+1) ans=d[h-1][i]+1;
		}
		if(ans<INF) printf("%d\n",ans);
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}
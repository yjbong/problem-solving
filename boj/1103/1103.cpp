#include <cstdio>
int N; // 보드의 세로 크기
int M; // 보드의 가로 크기

char board[50][50+1];
int d[50][50]; // d[i][j] = i,j 위치로 갈 수 있는 최대 이동 횟수
bool c[50][50]; // c[i][j] = 현재 경로에서 i,j를 이미 방문했는지 여부 (무한 이동 확인용)

bool infinity;

const int dy[4]={1,-1,0,0};
const int dx[4]={0,0,-1,1};

void go(int cy, int cx){

	// 무한히 이동 가능한 것을 이미 확인했으므로, 더 진행할 필요 없음
	if(infinity){
		return;
	}
	// 이미 방문한 곳을 또 방문하였음 (무한 이동 가능)
	if(c[cy][cx]){
		infinity = true;
		return;
	}

	c[cy][cx]=true;

	// 현재 위치에서 네 방향으로 이동
	for(int i=0; i<4; i++){
		int ny=cy+dy[i]*(board[cy][cx]-'0');
		int nx=cx+dx[i]*(board[cy][cx]-'0');
		// 보드를 벗어나지 않고, 구멍이 아닌 곳으로 이동
		if(ny>=0 && ny<N && nx>=0 && nx<M && board[ny][nx]!='H'){
			if(d[ny][nx]<d[cy][cx]+1){
				d[ny][nx]=d[cy][cx]+1;
				go(ny,nx);
			}
		}
	}
	c[cy][cx]=false;
}

int main(void){
	scanf("%d %d",&N,&M);
	for(int i=0; i<N; i++) scanf("%s",board[i]);

	go(0,0);
	if(infinity) printf("-1\n");
	else{
		int ans=0;
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				if(ans<d[i][j]+1) ans=d[i][j]+1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
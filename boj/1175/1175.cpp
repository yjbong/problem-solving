#include <cstdio>
#include <cstring>
#include <queue>
#define INF 1000000000
using namespace std;

typedef struct{
	int y;
	int x;
	int dir; // 이동 방향
	int chk1; // 1번 위치 선물 전달 여부
	int chk2; // 2번 위치 선물 전달 여부
}STAT;

int D[50][50][5][2][2]; // D[i][j][k][l][m] = 현재 위치가 (i,j)이고 마지막 이동방향이 k이며 (k==4 이면 직전에 이동이 없었던 것임)
			// 1번 위치에 선물 전달 여부가 l, 2번 위치에 선물 전달 여부가 m인 상태에 도달하기 위한 최소 이동 회수
int N; // 교실의 세로 크기
int M; // 교실의 가로 크기
char room[50][51];

const int dy[4]={-1,1,0,0};
const int dx[4]={0,0,1,-1};

int sy,sx; // 시작 y,x좌표
queue <STAT> q;

int main(void){
	scanf("%d %d\n",&N,&M);
	for(int i=0; i<N; i++) gets(room[i]);

	int num=1;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(room[i][j]=='C'){ room[i][j]=num+'0'; num++; }
			else if(room[i][j]=='S'){ sy=i; sx=j; }
		}
	}

	// D 초기화
	for(int i=0; i<N; i++)
	for(int j=0; j<M; j++)
	for(int k=0; k<5; k++)
	for(int l=0; l<2; l++)
	for(int m=0; m<2; m++)
		D[i][j][k][l][m]=INF;

	// 큐 초기화
	D[sy][sx][4][0][0]=0;
	STAT first;
	first.y=sy, first.x=sx;
	first.dir=4;
	first.chk1=0, first.chk2=0;
	q.push(first);

	while(!q.empty()){
		STAT f=q.front(); q.pop();
		for(int i=0; i<4; i++){
			if(i!=f.dir){ // 직전 이동방향과 달라야 함
				int cy=f.y+dy[i];
				int cx=f.x+dx[i];
				if(cy>=0 && cy<N && cx>=0 && cx<M && room[cy][cx]!='#'){ // (cy,cx)가 이동 가능한 위치인 경우
					int cchk1=(room[cy][cx]=='1'?1:f.chk1);
					int cchk2=(room[cy][cx]=='2'?1:f.chk2);
					if(D[cy][cx][i][cchk1][cchk2]>D[f.y][f.x][f.dir][f.chk1][f.chk2]+1){ // 새로운 상태를 큐에 넣는 의미가 있는 경우
						D[cy][cx][i][cchk1][cchk2]=D[f.y][f.x][f.dir][f.chk1][f.chk2]+1;
						STAT c;
						c.y=cy, c.x=cx;
						c.dir=i;
						c.chk1=cchk1, c.chk2=cchk2;
						q.push(c);
					}
				}
			}
		}
	}

	// 답 확인
	int ans=INF;
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			for(int k=0; k<5; k++)
				if(ans>D[i][j][k][1][1]) ans=D[i][j][k][1][1];

	if(ans<INF) printf("%d\n",ans);
	else printf("-1\n");

	return 0;
}
#include <cstdio>
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
int dy[4]={-1, 0, 1, 0};
int dx[4]={ 0, 1, 0,-1};

int left[4]={WEST,NORTH,EAST,SOUTH};

int N; // 세로 크기
int M; // 가로 크기

int r,c; // 청소기의 좌표
int d; // 청소기의 방향

int map[50][50];

int main(void){
	scanf("%d %d",&N,&M);
	scanf("%d %d %d",&r,&c,&d);
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++) scanf("%d",&map[i][j]);

	int ans=0;
	while(1){
		one:
		map[r][c]=2; // 현재 좌표 청소
		ans++;

		two:
		bool blankFound=false;
		for(int i=left[d]; ; i=left[i]){ // 청소가 안된 위치를 찾을때까지 왼쪽으로 회전해본다
			if(map[r+dy[i]][c+dx[i]]==0){ // 청소가 안된 위치를 찾음
				r+=dy[i];
				c+=dx[i];
				d=i;
				blankFound=true; break;
			}
			if(i==d) break;
		}

		if(blankFound) goto one;
		else{ // 네 방향이 모두 청소되어 있는 경우
			if(map[r-dy[d]][c-dx[d]]==1) break; // 후진이 불가능한 경우
			else{ // 후진이 가능한 경우
				r-=dy[d];
				c-=dx[d];
				goto two;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
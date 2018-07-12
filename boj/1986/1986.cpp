#include <cstdio>
#define MAX_N 1000
#define MAX_M 1000

int n; // 세로 길이
int m; // 가로 길이

int board[MAX_N][MAX_M];
// 퀸의 이동 방향
const int qdy[8]={-1,-1,-1, 0, 0, 1, 1, 1};
const int qdx[8]={-1, 0, 1,-1, 1,-1, 0, 1};
// 나이트의 이동 방향
const int kdy[8]={-2,-1, 1, 2, 2, 1,-1,-2};
const int kdx[8]={ 1, 2, 2, 1,-1,-2,-2,-1};

bool movable(int y, int x){
	if(y<0 || y>=n) return false;
	if(x<0 || x>=m) return false;
	if(board[y][x]=='Q') return false;
	if(board[y][x]=='K') return false;
	if(board[y][x]=='P') return false;
	return true;
}
int main(void){
	scanf("%d %d",&n,&m);
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++) board[i][j]='O';
	
	int queens;
	scanf("%d",&queens);
	for(int i=0; i<queens; i++){
		int y,x;
		scanf("%d %d",&y,&x);
		y--,x--;
		board[y][x]='Q';
	}
	int knights;
	scanf("%d",&knights);
	for(int i=0; i<knights; i++){
		int y,x;
		scanf("%d %d",&y,&x);
		y--,x--;
		board[y][x]='K';
	}
	int pawns;
	scanf("%d",&pawns);
	for(int i=0; i<pawns; i++){
		int y,x;
		scanf("%d %d",&y,&x);
		y--,x--;
		board[y][x]='P';
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			// 퀸으로 공격받는 위치 체크
			if(board[i][j]=='Q'){
				for(int k=0; k<8; k++){
					int cy=i+qdy[k];
					int cx=j+qdx[k];
					while(movable(cy,cx)){
						board[cy][cx]='X';
						cy+=qdy[k];
						cx+=qdx[k];
					}
				}
			}
			// 나이트로 공격받는 위치 체크
			else if(board[i][j]=='K'){
				for(int k=0; k<8; k++){
					int cy=i+kdy[k];
					int cx=j+kdx[k];
					if(movable(cy,cx)){
						board[cy][cx]='X';
					}
				}
			}
		}
	}

	// 안전한 위치의 개수 출력
	int ans=0;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(board[i][j]=='O') ans++;
	printf("%d\n",ans);
	return 0;
}
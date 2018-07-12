#include <cstdio>
int N; // 정삼각형 한 변의 길이
const int triangle[3][5]={{0,0,1,0,0},
			  {0,1,0,1,0},
			  {1,1,1,1,1}};

char ans[3072][3072*2];
char character(int size, int row, int col){
	if(size==3){
		if(triangle[row][col]) return '*';
		else return ' ';
	}

	// 3개의 triangle 영역의 왼쪽 위 점
	int topLeftRow[3], topLeftCol[3];
	topLeftRow[0]=0, topLeftCol[0]=size/2;
	topLeftRow[1]=size/2, topLeftCol[1]=0;
	topLeftRow[2]=size/2, topLeftCol[2]=size;

	for(int i=0; i<3; i++){
		if(topLeftRow[i]<=row && row<topLeftRow[i]+size/2 && topLeftCol[i]<=col && col<topLeftCol[i]+size-1){
			return character(size/2, row-topLeftRow[i], col-topLeftCol[i]);
		}
	}
	return ' ';
}
int main(void){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		for(int j=0; j<N*2-1; j++) ans[i][j]=character(N,i,j);
		ans[i][N*2-1]='\0';
	}
	for(int i=0; i<N; i++)
		printf("%s\n",ans[i]);
	return 0;
}
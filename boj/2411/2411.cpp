#include <cstdio>

int N; // map의 세로 길이
int M; // map의 가로 길이
int A; // 아이템의 개수
int B; // 장애물의 개수
int map[101][101]; // map[i][j]=0이면 빈칸, 1이면 아이템, 2이면 장애물
int d[101][101][201]; // d[i][j][k]=(1,1)에서 출발하여 (i,j)까지 이동하는 중에 아이템을 k개 먹는 경로의 가짓수

int main(void){
	scanf("%d %d %d %d",&N,&M,&A,&B);
	// 아이템 위치 업데이트
	for(int i=0; i<A; i++){
		int y,x;
		scanf("%d %d",&y,&x);
		map[y][x]=1;	
	}
	// 장애물 위치 업데이트
	for(int i=0; i<B; i++){
		int y,x;
		scanf("%d %d",&y,&x);
		map[y][x]=2;
	}

	int ans=0;

	// 아이템이 N+M-1개보다 많으면, 오른쪽 또는 위쪽으로만 이동하면서 모든 아이템을 먹는 방법은 없다.
	if(A<=N+M-1){

		for(int i=1; i<=N; i++){
			for(int j=1; j<=M; j++){
				// 시작점에 대한 초기화
				if(i==1 && j==1){
					if(map[1][1]==0){ // 시작점 (1,1)이 빈 칸
						 d[1][1][0]=1;
					}
					else if(map[1][1]==1){ // 시작점 (1,1)이 아이템이 있는 칸
						d[1][1][1]=1;
					}
					// 이외의 경우는 (1,1)에 장애물이 있으므로 (i,j)까지의 경로의 수가 0
				}
				else{
					for(int k=0; k<=A; k++){
						if(map[i][j]==0){ // (i,j)가 빈 칸
							d[i][j][k]=d[i-1][j][k]+d[i][j-1][k];
						}
						else if(map[i][j]==1){ // (i,j)가 아이템이 있는 칸
							if(k>0) d[i][j][k]=d[i-1][j][k-1]+d[i][j-1][k-1];
						}
						// 이외의 경우는 (i,j)에 장애물이 있으므로 (i,j)까지의 경로의 수가 0
					}	
				}
			}
		}

		ans=d[N][M][A];
	}
	printf("%d\n",ans);
	
	return 0;
}
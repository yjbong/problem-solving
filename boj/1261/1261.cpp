#include <cstdio>
#include <queue>
#include <utility>
#define INF 1000000000
#define MAX_N 100
#define MAX_M 100
using namespace std;
typedef pair<int,int> ii;
int n; // 세로 크기
int m; // 가로 크기
int b[MAX_N+2][MAX_M+2]; // b[i][j] = 위치(i,j)의 상태 (0: 빈 방, 1: 벽)
int d[MAX_N+2][MAX_M+2]; // d[i][j] = (1,1)에서 (i,j)까지 이동하기 위해 부수어야 하는 벽의 최소 개수

queue <ii> q;
const int dy[4]={1,-1,0,0};
const int dx[4]={0,0,-1,1};

int main(void){
	scanf("%d %d",&m,&n);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			scanf("%1d",&b[i][j]);
	// 미로의 경계
	for(int j=0; j<=m+1; j++) b[0][j]=b[n+1][j]=2;
	for(int i=0; i<=n+1; i++) b[i][0]=b[i][m+1]=2;

	// d 배열 초기화
	for(int i=0; i<=n+1; i++)
		for(int j=0; j<=m+1; j++) d[i][j]=INF;

	// BFS
	d[1][1]=0;
	q.push(make_pair(1,1));
	while(!q.empty()){
		ii f=q.front(); q.pop();
		int fy=f.first, fx=f.second;

		for(int i=0; i<4; i++){
			int cy=fy+dy[i], cx=fx+dx[i];
			if(b[cy][cx]==0){
				if(d[cy][cx]>d[fy][fx]){
					d[cy][cx]=d[fy][fx];
					q.push(make_pair(cy,cx));
				}
			}
			else if(b[cy][cx]==1){
				if(d[cy][cx]>d[fy][fx]+1){
					d[cy][cx]=d[fy][fx]+1;
					q.push(make_pair(cy,cx));
				}
			}
		}
	}
	printf("%d\n",d[n][m]);
	return 0;
}
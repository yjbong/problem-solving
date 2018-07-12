#include <cstdio>
#include <utility>
#include <queue>
using namespace std;
typedef pair<int,int> ii;
int N; // 세로 크기
int M; // 가로 크기
int orgMap[8][8];
int map[8][8];

const int dy[4]={-1,1,0,0};
const int dx[4]={0,0,1,-1};

int safeArea(){
	bool visited[8][8];
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++) visited[i][j]=false;

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(visited[i][j]==false && map[i][j]==2){
				queue <ii> q;
				q.push(make_pair(i,j));
				visited[i][j]=true;
				while(!q.empty()){
					int fy=q.front().first;
					int fx=q.front().second;
					q.pop();
					for(int k=0; k<4; k++){
						int cy=fy+dy[k];
						int cx=fx+dx[k];
						if(cy>=0 && cy<N && cx>=0 && cx<M && visited[cy][cx]==false && map[cy][cx]!=1){
							map[cy][cx]=2;
							q.push(make_pair(cy,cx));
							visited[cy][cx]=true;
						}
					}
				}
			}
		}
	}

	int ret=0;
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			if(map[i][j]==0) ret++;
	return ret;
}

int main(void){
	scanf("%d %d",&N,&M);
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			scanf("%d",&orgMap[i][j]);

	int ans=0;
	for(int i=0; i<N*M; i++)
	for(int j=i+1; j<N*M; j++)
	for(int k=j+1; k<N*M; k++)
	{
		int y0=i/M, x0=i%M;
		int y1=j/M, x1=j%M;
		int y2=k/M, x2=k%M;

		if(orgMap[y0][x0]==0 && orgMap[y1][x1]==0 && orgMap[y2][x2]==0){
			for(int l=0; l<N; l++)
				for(int m=0; m<M; m++)
					map[l][m]=orgMap[l][m];
			map[y0][x0]=map[y1][x1]=map[y2][x2]=1;
			int curAns=safeArea();
			if(ans<curAns) ans=curAns;
		}
		
	}
	printf("%d\n",ans);
	return 0;
}
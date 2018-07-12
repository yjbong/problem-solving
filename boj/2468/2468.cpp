#include <cstdio>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int,int> ii;

int N;
int h[100][100];
bool visited[100][100];

const int dy[4]={-1,1,0,0};
const int dx[4]={0,0,1,-1};

queue <ii> q;

int main(void){
	scanf("%d",&N);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++) scanf("%d",&h[i][j]);

	int ans=0;
	for(int i=0; i<=100; i++){ // 물에 잠기는 높이가 0~100 일 때를 모두 해본다
		int curAns=0;
		for(int j=0; j<N; j++)
			for(int k=0; k<N; k++) visited[j][k]=false;
		
		for(int j=0; j<N; j++){
			for(int k=0; k<N; k++){
				if(h[j][k]>i && visited[j][k]==false){
					curAns++;
					q.push(make_pair(j,k));
					visited[j][k]=true;
					while(!q.empty()){
						ii f=q.front(); q.pop();
						int fy=f.first, fx=f.second;

						for(int l=0; l<4; l++){
							int cy=fy+dy[l], cx=fx+dx[l];
							if(cy>=0 && cy<N && cx>=0 && cx<N && h[cy][cx]>i && visited[cy][cx]==false){
								q.push(make_pair(cy,cx));
								visited[cy][cx]=true;	
							}
						}
					}
				}
			}
		}
		if(ans<curAns) ans=curAns; // 안전 영역의 수를 업데이트
	}

	printf("%d\n",ans);
	return 0;
}
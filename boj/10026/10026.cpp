#include <cstdio>
#include <queue>
#include <utility>
#define MAX_N 100
using namespace std;
typedef pair<int,int> ii;
int N;
char board[MAX_N][MAX_N+1];
bool check[MAX_N][MAX_N];

queue <ii> q;
const int dy[4]={1,-1,0,0};
const int dx[4]={0,0,-1,1};

int main(void){
	scanf("%d\n",&N);
	for(int i=0; i<N; i++) gets(board[i]);

	int ans;

	// 정상인의 경우
	ans=0;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++) check[i][j]=false;

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(!check[i][j]){
				ans++;
				char curColor=board[i][j];
				check[i][j]=true;
				q.push(make_pair(i,j));
				while(!q.empty()){
					ii f=q.front(); q.pop();
					int fy=f.first, fx=f.second;
					for(int k=0; k<4; k++){
						int cy=fy+dy[k], cx=fx+dx[k];
						if(cy>=0 && cy<N && cx>=0 && cx<=N && check[cy][cx]==false){
							if(board[cy][cx]==curColor){
								check[cy][cx]=true;
								q.push(make_pair(cy,cx));
							}
						}
					}
				}
			}
		}
	}
	printf("%d ",ans);

	// 적록색약의 경우
	ans=0;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++) check[i][j]=false;

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(!check[i][j]){
				ans++;
				char curColor=board[i][j];
				check[i][j]=true;
				q.push(make_pair(i,j));
				while(!q.empty()){
					ii f=q.front(); q.pop();
					int fy=f.first, fx=f.second;
					for(int k=0; k<4; k++){
						int cy=fy+dy[k], cx=fx+dx[k];
						if(cy>=0 && cy<N && cx>=0 && cx<=N && check[cy][cx]==false){
							if(board[cy][cx]==curColor || (board[cy][cx]=='R' && curColor=='G') || (board[cy][cx]=='G' && curColor=='R')){
								check[cy][cx]=true;
								q.push(make_pair(cy,cx));
							}
						}
					}
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
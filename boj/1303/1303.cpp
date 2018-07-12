#include <cstdio>
#include <queue>

using namespace std;
typedef pair<int,int> ii;
int n,m;
char board[111][111];
bool visit[111][111];
queue <ii> q;
const int dy[4]={-1,1,0,0};
const int dx[4]={0,0,1,-1};

int main(void){

	scanf("%d %d",&n,&m);

	for(int i=1; i<=m; i++) scanf("%s",board[i]+1);

	for(int i=0; i<=m+1; i++) board[i][0]=board[i][n+1]='X';
	for(int j=0; j<=n+1; j++) board[0][j]=board[m+1][j]='X';

	int myPower=0, enemyPower=0;
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			if(!visit[i][j]){
				char color=board[i][j];
				int size=1;
				q.push(make_pair(i,j));
				visit[i][j]=true;
				while(!q.empty()){
					ii f=q.front(); q.pop();
					int fy=f.first, fx=f.second;
					for(int k=0; k<4; k++){
						int cy=fy+dy[k], cx=fx+dx[k];
						if(visit[cy][cx]==false && board[cy][cx]==color){
							size++;
							q.push(make_pair(cy,cx));
							visit[cy][cx]=true;
						}
					}
				}
				if(color=='W') myPower += size*size;
				else enemyPower += size*size;
			}
		}
	}
	printf("%d %d\n",myPower,enemyPower);
	return 0;
}
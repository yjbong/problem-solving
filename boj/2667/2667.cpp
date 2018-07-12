#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;

int N;
int b[25][25];
bool visit[25][25];

queue <ii> q;
const int dy[4]={1,-1,0,0};
const int dx[4]={0,0,-1,1};

vector <int> ans;

int main(void){
	scanf("%d",&N);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++) scanf("%1d",&b[i][j]);

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(b[i][j] && visit[i][j]==false){
				visit[i][j]=true;
				q.push(make_pair(i,j));
				int size=1;
				while(!q.empty()){
					ii f=q.front(); q.pop();
					int fy=f.first, fx=f.second;
					for(int k=0; k<4; k++){
						int cy=fy+dy[k], cx=fx+dx[k];
						if(cy>=0 && cy<N && cx>=0 && cx<N && b[cy][cx] && visit[cy][cx]==false){
							visit[cy][cx]=true;
							q.push(make_pair(cy,cx));
							size++;
						}
					}
				}
				ans.push_back(size);	
			}
		}
	}
	if(ans.size()>0) sort(ans.begin(),ans.end());

	printf("%d\n",ans.size());
	for(int i=0; i<ans.size(); i++) printf("%d\n",ans[i]);
	
	return 0;
}
#include <cstdio>
#include <queue>
#include <map>
#include <utility>
#include <vector>
#define MAX_N 50
#define MAX_M 50
using namespace std;
typedef pair<int,int> ii;

int N,M; // 섬의 지도 크기
char input[MAX_N+2][MAX_M+2]; // 섬의 지도
int mark[MAX_N+2][MAX_M+2];
int tmp[MAX_N+2][MAX_M+2];
int islands; // 섬의 개수

int parent[MAX_N*MAX_M+1]; // parent[i] = 섬 i를 포함하는 섬
vector<int> children[MAX_N*MAX_M+1]; // children[i] = 섬 i가 포함하는 섬들
int height[MAX_N*MAX_M+1]; // height[i] = i번 섬의 높이
int cnt[MAX_N*MAX_M]; // cnt[i] = 높이가 i인 섬의 개수

const int dy8[8]={-1,-1,-1, 0, 0, 1, 1, 1};
const int dx8[8]={-1, 0, 1,-1, 1,-1, 0, 1};
const int dy4[4]={-1, 1, 0, 0};
const int dx4[4]={ 0, 0,-1, 1};

void marking(int id, int y, int x){
	mark[y][x]=id;
	for(int i=0; i<8; i++){
		int ny=y+dy8[i], nx=x+dx8[i];
		if(input[ny][nx]!='.' && !mark[ny][nx]) marking(id,ny,nx);
	}
}

queue <ii> q;
vector <int> top;
bool check[MAX_N*MAX_M+1];

void findChildren(int id){
	while(!q.empty()) q.pop();
	for(int i=0; i<=N+1; i++)
		for(int j=0; j<=M+1; j++)
			if(mark[i][j]==id) q.push(make_pair(i,j));

	while(!q.empty()){
		ii f = q.front(); q.pop();
		int fy=f.first, fx=f.second;
		for(int i=0; i<4; i++){
			int cy=fy+dy4[i], cx=fx+dx4[i];
			if(cy>=0 && cy<=N+1 && cx>=0 && cx<=M+1){
				if(mark[cy][cx]==0){
					mark[cy][cx]=id;
					q.push(make_pair(cy,cx));
				}
				else if(mark[cy][cx]!=id && mark[cy][cx]!=parent[id] && check[mark[cy][cx]]==false){ // 자식 섬을 찾음
					if(id<0) top.push_back(mark[cy][cx]);
					else children[id].push_back(mark[cy][cx]);
					parent[mark[cy][cx]]=id;
					check[mark[cy][cx]]=true;
				}
			}
		}
	}

	// 자식 섬들에 대해 재귀호출
	if(id<0) for(int i=0; i<top.size(); i++) findChildren(top[i]);
	else for(int i=0; i<children[id].size(); i++) findChildren(children[id][i]);
}

int getHeight(int idx){
	if(height[idx]>=0) return height[idx];
	if(children[idx].size()==0) return height[idx]=0;

	int maxChildHeight=0;
	for(int i=0; i<children[idx].size(); i++){
		int curChildHeight = getHeight(children[idx][i]);
		if(maxChildHeight < curChildHeight) maxChildHeight = curChildHeight;
	}

	return height[idx]=maxChildHeight+1;
}

int main() {
	scanf("%d %d\n",&N,&M);
	for(int i=1; i<=N; i++) scanf("%s",input[i]+1);

	// 경계를 -1번 섬으로 한다.
	for(int i=0; i<=N+1; i++) mark[i][0]=mark[i][M+1]=-1;
	for(int j=0; j<=M+1; j++) mark[0][j]=mark[N+1][j]=-1;

	// 각 섬의 영역 표시
	int islands=0;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			if(input[i][j]!='.' && !mark[i][j]){
				islands++;
				marking(islands,i,j);
			}
		}
	}

	for(int i=1; i<=islands; i++) parent[i] = 0;
	findChildren(-1); // -1번 섬(경계)으로부터 포함되는 섬들을 찾는다.

	// 각 섬의 높이 계산
	for(int i=1; i<=islands; i++) height[i] = -1;
	for(int i=1; i<=islands; i++) height[i] = getHeight(i);

	// 출력
	int maxHeight = -1;
	for(int i=1; i<=islands; i++){
		if(maxHeight < height[i]) maxHeight = height[i];
		cnt[height[i]]++;
	}
    
    if(maxHeight<0) printf("-1");
	else for(int i=0; i<=maxHeight; i++) printf("%d ",cnt[i]);
	printf("\n");
	return 0;
}
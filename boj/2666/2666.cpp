#include <cstdio>
#include <queue>
#include <utility>
#define INF 100000000
using namespace std;
typedef pair<int,int> ii;

int n; // 벽장의 개수
int m; // 사용할 벽장 순서의 길이
int o[20]; // o[i] = i번째로 사용할 벽장의 번호 (i는 0부터)
int s0,s1; // s0, s1 = 최초에 열려있는 두 벽장의 번호

int d[20][20]; // d[i][j] = o[i]까지 처리했으며(즉, o[i]가 열려있음), 열려있는 다른 벽장의 번호가 j가 되기 위한 최소 이동 횟수
int move[20][20][20][20]; // 열린 벽장이 (i,j)인 상태에서 (k,l)로 바뀌기 위한 최소 이동 횟수

int main(void){

	// 입력
	scanf("%d",&n);	
	scanf("%d %d",&s0,&s1);
	s0--, s1--; // 벽장 번호는 0부터 시작하는 것으로 변경

	if(s0>s1){ int tmp=s0; s0=s1; s1=s0; } // s0은 s1보다 작게

	scanf("%d",&m);
	for(int i=0; i<m; i++){
		scanf("%d",&o[i]);
		o[i]--; // 벽장 번호는 0부터 시작하는 것으로 변경
	}

	// move 계산
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){

			for(int k=0; k<n; k++)
				for(int l=k+1; l<n; l++) move[i][j][k][l]=INF;
				
			queue <ii> q;

			move[i][j][i][j]=0;
			q.push(make_pair(i,j));
			while(!q.empty()){
				ii f=q.front(); q.pop();
				int f0=f.first, f1=f.second;

				// f0을 왼쪽으로 한칸 이동
				if(f0>0){
					if(move[i][j][f0-1][f1]>move[i][j][f0][f1]+1){
						move[i][j][f0-1][f1]=move[i][j][f0][f1]+1;
						q.push(make_pair(f0-1,f1));
					}
				}
				// f0을 오른쪽으로 한칸 이동
				if(f0+1<f1){
					if(move[i][j][f0+1][f1]>move[i][j][f0][f1]+1){
						move[i][j][f0+1][f1]=move[i][j][f0][f1]+1;
						q.push(make_pair(f0+1,f1));
					}
				}
				// f1을 왼쪽으로 한칸 이동
				if(f0<f1-1){
					if(move[i][j][f0][f1-1]>move[i][j][f0][f1]+1){
						move[i][j][f0][f1-1]=move[i][j][f0][f1]+1;
						q.push(make_pair(f0,f1-1));
					}
				}
				// f1을 오른쪽으로 한칸 이동
				if(f1+1<n){
					if(move[i][j][f0][f1+1]>move[i][j][f0][f1]+1){
						move[i][j][f0][f1+1]=move[i][j][f0][f1]+1;
						q.push(make_pair(f0,f1+1));
					}
				}
			}
		}
	}

	// d의 초기화
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++) d[i][j]=INF;

	// d[0][j]의 초기화
	for(int j=0; j<n; j++){
		if(o[0]<j) d[0][j]=move[s0][s1][o[0]][j];
		else if(o[0]>j) d[0][j]=move[s0][s1][j][o[0]];
	}

	// DP
	for(int i=1; i<m; i++){
		for(int j=0; j<n; j++){
			// 각 d[i-1][k]에서 답을 만드는 경우를 고려
			for(int k=0; k<n; k++){
				int curMoveAdd=INF;
				if(o[i]<j){
					if(o[i-1]<k) curMoveAdd=move[o[i-1]][k][o[i]][j];
					else if(o[i-1]>k) curMoveAdd=move[k][o[i-1]][o[i]][j];
				}
				else if(o[i]>j){
					if(o[i-1]<k) curMoveAdd=move[o[i-1]][k][j][o[i]];
					else if(o[i-1]>k) curMoveAdd=move[k][o[i-1]][j][o[i]];
				}

				if(d[i][j]>d[i-1][k]+curMoveAdd) d[i][j]=d[i-1][k]+curMoveAdd;
			}
		}
	}

	// 답 출력
	int ans=INF;
	for(int j=0; j<n; j++)
		if(ans>d[m-1][j]) ans=d[m-1][j];
	printf("%d\n",ans);
	
	return 0;
}
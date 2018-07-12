#include <cstdio>
#include <cstdlib>
#include <stack>
#define MAX_N 20 // 논의 최대 크기
#define MAX_H 100 // 1개 구역의 최대 수확량
#define INF 1000000000
using namespace std;
int N; // 논의 크기
int H[MAX_N+1][MAX_N+1]; // H[i][j] = (i,j)구역의 예상 수확량 (i행은 아래에서부터 높이가 i인 것임)

// D[i][j][k] = 전체 논 중 (1~i)열에 대하여, 규칙을 지키면서 형이 배분받았고 i열에서 형이 배분받은 논은 아래쪽 j개일 때
//		k=(동생의 예상 수확량-형의 예상 수확량 + 20*20*100(diff) ) 인 경우가 가능하면 true, 아니면 false
bool D[MAX_N+1][MAX_N+1][MAX_N*MAX_N*MAX_H*2+1];

// T[i][j][k] = D[i][j][k]에 대한 trace
char T[MAX_N+1][MAX_N+1][MAX_N*MAX_N*MAX_H*2+1];

int delta[MAX_N+1][MAX_N+1]; // delta[i][j]=i열에서 형이 아래쪽 j개 구역을 가져갈 때 diff의 변화량

int main(void){

	scanf("%d",&N);
	for(int i=N; i>=1; i--)
		for(int j=1; j<=N; j++) scanf("%d",&H[i][j]);

	// delta 계산
	for(int i=1; i<=N; i++){
		for(int j=0; j<=N; j++){
			delta[i][j]=0;
			for(int k=1; k<=N; k++){
				if(k<=j) delta[i][j]-=H[k][i];
				else delta[i][j]+=H[k][i];
			}
		}
	}

	// D배열 초기화
	for(int j=0; j<=N; j++)
		D[1][j][MAX_N*MAX_N*MAX_H + delta[1][j]]=true;

	// bottom-up DP
	for(int i=2; i<=N; i++){
		for(int j=0; j<=N; j++){
			for(int k=MAX_N*MAX_N*MAX_H - MAX_N*i*MAX_H; k<=MAX_N*MAX_N*MAX_H + MAX_N*i*MAX_H; k++){
				D[i][j][k]=0;
				if(k-delta[i][j]>=0 && k-delta[i][j]<=MAX_N*MAX_N*MAX_H*2){
					for(int l=0; l<=j; l++){
						if(D[i-1][l][k-delta[i][j]]){
							D[i][j][k]=true;
							T[i][j][k]=l; // 형이 i-1번 열에서는 아래쪽 l개 구역을 가져감
							break;
						}
					}
				}
			}
		}
	}

	// 수확량의 최소 차이 확인
	int ans=INF;
	for(int j=0; j<=N; j++){
		for(int k=0; k<=MAX_N*MAX_N*MAX_H*2; k++){
			if(D[N][j][k] && ans>abs(k-MAX_N*MAX_N*MAX_H)) ans=abs(k-MAX_N*MAX_N*MAX_H);
		}
	}
	printf("%d\n",ans);

	// 최소 차이를 만드는 방법 확인
	stack <int> seq;
	for(int j=0; j<=N; j++){
		for(int k=0; k<=MAX_N*MAX_N*MAX_H*2; k++){
			if(D[N][j][k] && ans==abs(k-MAX_N*MAX_N*MAX_H)){
				// trace 시작
				int curCells=j;
				int curDiff=k;
				for(int l=N; l>=1; l--){
					seq.push(curCells);
					if(l>1){
						int tmp=curCells;
						curCells=T[l][tmp][curDiff];
						curDiff-=delta[l][tmp];
					}
				}

				goto out;
			}
		}
	}

out:
	while(!seq.empty()){
		printf("%d ",seq.top());
		seq.pop();
	}
	printf("\n");

	return 0;
}
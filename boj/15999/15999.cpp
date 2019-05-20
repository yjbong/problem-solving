#include <cstdio>
#define MOD 1000000007
#define MAX_N 2000
#define MAX_M 2000
int N,M; // 격자판의 행, 열의 수
char grid[MAX_N][MAX_M+1];
const int dy[4]={-1,1,0,0};
const int dx[4]={0,0,1,-1};
int main() {
	scanf("%d %d\n",&N,&M);
	for(int i=0; i<N; i++) scanf("%s\n",grid[i]);

	// 현재 상태에서 경계에 있는 셀은 초기 상태에서도 그대로일 수 밖에 없다.
	// 예를 들자면 현재 BW 로 되어 있는 부분은 이전에도 BW이었을 수 밖에 없다. 왜냐면,
	// 1. 이전 상태에서 해당 부분이 WW였다면, 다음에 가능한 값은 WW 또는 BB 뿐이다.
	// 2. 이전 상태에서 해당 부분이 BB였다면, 다음에 가능한 값은 BB 또는 WW 뿐이다.
	// 3. 이전 상태에서 해당 부분이 WB였다면, 이 부분이 BW가 되기 위해서는 WW 또는 BB인 상태를 거칠 수 밖에 없는데, 두 상태 모두 BW로 변경될 수 있는 방법은 없다.
	// 위의 이유로 경계에 있는 셀들은 변경되지 않기 때문에, 현재 상태에서 경계에 있지 않은 내부 셀(인접 셀이 모두 같은 색인 경우)들은 초기 상태에서 어떻게 칠해져 있든지 상관이 없다.

	int ans=1;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			// 셀 (i,j)에 인접한 다른 색의 셀이 있는지 확인
			bool changeable=true;
			for(int k=0; k<4; k++){
				int cy=i+dy[k], cx=j+dx[k];
				if(cy>=0 && cy<N && cx>=0 && cx<M && grid[i][j]!=grid[cy][cx]){ changeable=false; break; }
			}
			// 인접한 셀 중 다른 색이 없는 경우, 셀 (i,j)는 맘대로 칠해도 된다. 즉, 경우의 수가 2배로 된다.
			if(changeable) ans=(ans*2)%MOD;
		}
	}
	printf("%d\n",ans);
	return 0;
}
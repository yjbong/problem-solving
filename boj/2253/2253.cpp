#include <cstdio>
#define INF 1000000000
int n; // 돌의 개수 (1~n번 돌)
int m; // 크기가 작은 돌의 개수

// 어떤 경우라도 최고 속도는 141을 넘을 수 없음 (1+2+3+ ... +141 = 10011 > 10000 이므로)

int d[10001][150]; // d[i] = i번 돌에 도달했을 때의 속도가 j인 상태가 되기 위한 최소 점프 횟수
bool small[10001]; // small[i] = i번 돌의 크기가 작아서 올라설 수 없다면 true, 그렇지 않다면 false

int min2(int a, int b){ return a<b?a:b; }
int main(void){

	// 입력
	scanf("%d %d",&n,&m);
	for(int i=0; i<m; i++){
		int curSmall;
		scanf("%d",&curSmall);
		small[curSmall]=true;
	}

	// DP 테이블 초기화
	for(int i=1; i<=n; i++)
		for(int j=0; j<150; j++)
			d[i][j]=INF;

	// 최초에는 1번 돌에 위치해 있고 그 때의 속도는 0 이다
	d[1][0]=0;

	// 2번 돌부터 DP
	for(int i=2; i<=n; i++){
		// 속도가 0일 수는 없기 때문에 j=1부터 시작 (점프는 반드시 한 칸 이상 해야 하므로)
		for(int j=1; j<150; j++){
			// 현재 속도가 j라면, (i-j)번 돌에서 점프하여 온 것이고,
			// 이 때 (i-j)번 돌에서의 가능한 속도는 j-1, j, j+1 의 3가지임
			if(small[i]==false && i-j>0){
				d[i][j]=min2(d[i][j],d[i-j][j-1]+1);
				d[i][j]=min2(d[i][j],d[i-j][j]+1);
				d[i][j]=min2(d[i][j],d[i-j][j+1]+1);
			}
		}
	}

	// 답 출력
	int ans=INF;
	for(int j=0; j<150; j++) ans=min2(ans,d[n][j]);
	if(ans<INF) printf("%d\n",ans);
	else printf("-1\n");

	return 0;
}
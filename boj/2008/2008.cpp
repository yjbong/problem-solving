#include <cstdio>
#include <cstdlib>
#define INF 1000000000000000ll
#define MAX_N 100
#define MAX_M 500
typedef long long ll;
int N; // 세로선의 개수 (1~N번 세로선)
int M; // 가로선의 개수 (1~M번 가로선)
int start; // 시작 위치 세로선의 번호
int end; // 목표 위치 세로선의 번호
ll del; // 가로선 1개 제거 비용
ll add; // 가로선 1개 추가 비용

int c[MAX_M+1]; // c[i]=x이면 i번 가로선이 x와 x+1번 세로선 사이를 연결하는 것임

ll d[MAX_M+1][MAX_N+1]; // d[i][j] = 현재 위치의 높이가 i-1번 가로선과 i번 가로선 사이이며, j번 세로선 상에 있을 때 목적지(아래의 end번 세로선)에 도달하기 위한 최소 조작 비용

ll min2(ll a, ll b){ return a<b?a:b;}
ll go(int height, int line){ // go(height, line) = 현재 높이가 (height-1)번 가로선과 height번 가로선 사이이며, line번 세로선 상에 있을 때
	if(height==M+1){
		return abs(line-end)*add;
	}
	if(d[height][line]>=0) return d[height][line]; // memoization

	ll ret=INF;

	// 현재 세로선 idx < c[height] 일 때
	if(line < c[height]){
		// 현재 세로선에서 (1 ~ c[height]-1) 번 세로선으로 이동할 때는, 인덱스 차이만큼 가로선을 추가함
		for(int i=1; i<c[height]; i++) ret=min2(ret, go(height+1,i)+abs(line-i)*add);
		
		// 현재 세로선에서 c[height] 번 세로선으로 이동할 때는, 인덱스 차이만큼 가로선을 추가한 후,
		// height번째 가로선을 지우거나, 바로 아래에 새로운 가로선을 추가해야 함 (가로선 c[height]가 방해됨)
		ret=min2(ret, go(height+1,c[height])+abs(line-c[height])*add+min2(add,del));

		// 현재 세로선에서 (c[height]+1 ~ N) 번 세로선으로 이동할 때는, (인덱스 차이-1)만큼 가로선을 추가함 (가로선 c[height]가 활용됨)
		for(int i=c[height]+1; i<=N; i++) ret=min2(ret, go(height+1,i)+(abs(line-i)-1)*add);
	}

	// 현재 세로선 idx == c[height] 일 때
	else if(line == c[height]){
		// 현재 세로선에서 (1 ~ c[height]) 번 세로선으로 이동할 때는, 인덱스 차이만큼 가로선을 추가한 후,
		// height번째 가로선을 지우거나, 바로 아래에 새로운 가로선을 추가해야 함 (가로선 c[height]가 방해됨)
		for(int i=1; i<=c[height]; i++) ret=min2(ret, go(height+1,i)+abs(line-i)*add+min2(add,del));

		// 현재 세로선에서 (c[height]+1 ~ N) 번 세로선으로 이동할 때는, (인덱스 차이-1)만큼 가로선을 추가함 (가로선 c[height]가 활용됨)
		for(int i=c[height]+1; i<=N; i++) ret=min2(ret, go(height+1,i)+(abs(line-i)-1)*add);
	}

	// 현재 세로선 idx == c[height]+1 일 때
	else if(line == c[height]+1){
		// 현재 세로선에서 (1 ~ c[height]) 번 세로선으로 이동할 때는, (인덱스 차이-1)만큼 가로선을 추가함 (가로선 c[height]가 활용됨)
		for(int i=1; i<=c[height]; i++) ret=min2(ret, go(height+1,i)+(abs(line-i)-1)*add);

		// 현재 세로선에서 (c[height]+1 ~ N) 번 세로선으로 이동할 때는, 인덱스 차이만큼 가로선을 추가한 후,
		// height번째 가로선을 지우거나, 바로 아래에 새로운 가로선을 추가해야 함 (가로선 c[height]가 방해됨)
		for(int i=c[height]+1; i<=N; i++) ret=min2(ret, go(height+1,i)+abs(line-i)*add+min2(add,del));
	}

	// 현재 세로선 idx > c[height]+1 일 때
	else if(line > c[height]+1){
		// 현재 세로선에서 (1 ~ c[height]) 번 세로선으로 이동할 때는, (인덱스 차이-1)만큼 가로선을 추가함 (가로선 c[height]가 활용됨)
		for(int i=1; i<=c[height]; i++) ret=min2(ret, go(height+1,i)+(abs(line-i)-1)*add);

		// 현재 세로선에서 c[height]+1 번 세로선으로 이동할 때는, 인덱스 차이만큼 가로선을 추가한 후,
		// height번째 가로선을 지우거나, 바로 아래에 새로운 가로선을 추가해야 함 (가로선 c[height]가 방해됨)
		ret=min2(ret, go(height+1,c[height]+1)+abs(line-(c[height]+1))*add+min2(add,del));

		// 현재 세로선에서 (c[height]+2 ~ N) 번 세로선으로 이동할 때는, 인덱스 차이만큼 가로선을 추가함
		for(int i=c[height]+2; i<=N; i++) ret=min2(ret, go(height+1,i)+abs(line-i)*add);
	}

	return (d[height][line]=ret);
}

int main(void){
	scanf("%d %d",&N,&M);
	scanf("%d %d %lld %lld",&start,&end,&del,&add);
	for(int i=1; i<=M; i++) scanf("%d",&c[i]);

	for(int i=0; i<=M; i++)
		for(int j=0; j<=N; j++)
			d[i][j]=-1;
	printf("%lld\n",go(1,start));
	return 0;
}
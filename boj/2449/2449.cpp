#include <cstdio>
#define INF 1000000000

int N; // 전구의 수
int K; // 전구가 표현할 수 있는 색의 수
int c[201]; // c[i] = i번 전구의 색
int d[201][201][21]; // d[i][j][k] = i~j번 전구를 모두 k색으로 만들기 위한 최소 바꿈 회수
int min2(int a, int b){ return a<b?a:b; }
int main(void){
	scanf("%d %d",&N,&K);
	for(int i=0; i<N; i++) scanf("%d",&c[i]);

	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			for(int k=0; k<=K; k++) d[i][j][k]=INF;

	// 구간 크기가 1인 경우에 대한 초기화
	for(int j=0; j<N; j++){
		for(int k=1; k<=K; k++){
			if(c[j]==k) d[j][j][k]=0;
			else d[j][j][k]=1;
		}
	}

	// 구간 크기가 2 이상 --> DP
	for(int i=1; i<N; i++){
		for(int j=0; j+i<N; j++){
			
			// k색으로 칠해진 두 부분을 합치는 경우
			for(int k=1; k<=K; k++)
				for(int l=j; l<j+i; l++)
					d[j][j+i][k]=min2(d[j][j+i][k], d[j][l][k]+d[l+1][j+i][k]);

			// j~j+i 구간을 모두 l색(l!=k)으로 칠한 후, 1번 바꿔서 모두 k색으로 칠하는 경우
			for(int k=1; k<=K; k++)
				for(int l=1; l<=K; l++)
					if(l!=k) d[j][j+i][k]=min2(d[j][j+i][k],d[j][j+i][l]+1);
		}
	}

	// 답 출력
	int ans=INF;
	for(int k=1; k<=K; k++)
		ans=min2(ans, d[0][N-1][k]);
	printf("%d\n",ans);
	
	return 0;
}
#include <cstdio>

#define INF 1111111111
int n; // 가로등 개수
int m; // 로봇이 처음에 위치한 가로등 번호

int p[1111]; // p[i] = i번째 가로등 위치
int w[1111]; // w[i] = i번째 가로등의 1초당 소비전력
int s[1111]; // s[i] = w[1]+w[2]+ ... + w[i]

// d[i][j][0] = 가로등 a[i]~a[j]를 끄고, 현재 위치가 a[i]일 때 a[i]를 끈 시각까지 소비된 전력 총합의 최소값
// d[i][j][1] = 가로등 a[i]~a[j]를 끄고, 현재 위치가 a[j]일 때 a[j]를 끈 시각까지 소비된 전력 총합의 최소값
int d[1111][1111][2];

int min2(int a, int b){ return a<b?a:b; }
int main(void){

	// 입력
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++) scanf("%d %d",&p[i],&w[i]);

	// s 계산
	s[0]=0; s[1]=w[1];
	for(int i=2; i<=n; i++) s[i]=s[i-1]+w[i];

	// d 초기화
	for(int i=0; i<n; i++)
		for(int j=1; j+i<=n; j++)
			d[j][j+i][0]=d[j][j+i][1]=INF;

	d[m][m][0]=d[m][m][1]=0;

	// d 계산
	for(int i=1; i<n; i++){
		for(int j=1; j+i<=n; j++){
			d[j][j+i][0]=min2(d[j][j+i][0], d[j+1][j+i][0]+(s[j]+s[n]-s[j+i])*(p[j+1]-p[j]));
			d[j][j+i][0]=min2(d[j][j+i][0], d[j+1][j+i][1]+(s[j]+s[n]-s[j+i])*(p[j+i]-p[j]));

			d[j][j+i][1]=min2(d[j][j+i][1], d[j][j+i-1][0]+(s[j-1]+s[n]-s[j+i-1])*(p[j+i]-p[j]));
			d[j][j+i][1]=min2(d[j][j+i][1], d[j][j+i-1][1]+(s[j-1]+s[n]-s[j+i-1])*(p[j+i]-p[j+i-1]));
		}
	}
	
	// 답 출력
	int ans=min2(d[1][n][0],d[1][n][1]);
	printf("%d\n",ans);
	return 0;
}
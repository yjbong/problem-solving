#include <cstdio>
#define MAX_N 1000
int n; // 쓰레기의 개수
int a[MAX_N+1]; // a[i] = 첫째날 i번째로 놓인 쓰레기의 양 (i는 1부터)
int b[MAX_N+1]; // b[i] = 둘째날 i번째로 놓인 쓰레기의 양
int d[MAX_N+1][MAX_N+1]; // d[i][j] = a[1~i]가 있을 때, b[j]를 마지막으로 하는 최장공통증가부분수열(LCIS)의 길이
int max2(int a, int b){ return a>b?a:b; }
int main(void){
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	for(int i=1; i<=n; i++) scanf("%d",&b[i]);

	for(int i=1; i<=n; i++){
		int maxPre=0;
		for(int j=1; j<=n; j++){
			d[i][j]=d[i-1][j];
			if(b[j]==a[i]) d[i][j]=max2(d[i][j],maxPre+1);
			else if(b[j]<a[i]) maxPre=max2(maxPre, d[i][j]);
		}
	}

	int ans=0;
	for(int i=1; i<=n; i++) ans=max2(ans,d[n][i]);
	printf("%d\n",ans);
	return 0;
}
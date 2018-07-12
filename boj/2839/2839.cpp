#include <cstdio>
#define INF 10000000
int N;
int d[5001]; // d[i] = 설탕 i킬로그램을 배달하기 위한 최소 봉지 개수
int min2(int a, int b){ return a<b?a:b; }
int go(int n){
	if(n==0) return 0;
	if(d[n]>=0) return d[n];
	int ret=INF;
	if(n>=3) ret=min2(ret,go(n-3)+1);
	if(n>=5) ret=min2(ret,go(n-5)+1);
	return (d[n]=ret);
}
int main(void){
	scanf("%d",&N);
	for(int i=1; i<=N; i++) d[i]=-1;
	int ans=go(N);
	if(ans<INF) printf("%d\n",ans);
	else printf("-1\n");
	return 0;
}
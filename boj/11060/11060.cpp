#include <cstdio>
#define INF 1000000000
int n;
int a[1001];
int d[1001];
int main(void){

	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%d",&a[i]);

	// d 초기화
	d[0]=0;
	for(int i=1; i<n; i++) d[i]=INF;

	// d 계산
	for(int i=1; i<n; i++)
		for(int j=0; j<i; j++)
			if(a[j]>=i-j && d[i]>d[j]+1) d[i]=d[j]+1;

	// 출력
	if(d[n-1]<INF) printf("%d\n",d[n-1]);
	else printf("-1\n");
	return 0;
}
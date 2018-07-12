#include <cstdio>
int N; // 숫자의 개수
int a[111]; // a[i] = i번째 숫자
int lastnum; // 마지막 숫자
long long d[111][21]; // d[i][j] = 왼쪽에서부터 i번째 숫자까지 사용했을 때, 답이 j가 되는 경우의 수
int main(void){
	scanf("%d",&N);
	for(int i=0; i<N-1; i++) scanf("%d",&a[i]);
	scanf("%d",&lastnum);

	d[0][a[0]]=1ll;
	for(int i=1; i<N-1; i++){
		for(int j=0; j<=20; j++){
			// a[i]를 더한 경우
			if(j-a[i]>=0) d[i][j]+=d[i-1][j-a[i]];
			// a[i]를 뺀 경우
			if(j+a[i]<=20) d[i][j]+=d[i-1][j+a[i]];
		}
	}
	printf("%lld\n",d[N-2][lastnum]);
	return 0;
}
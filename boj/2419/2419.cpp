#include <cstdio>
#include <algorithm>
#define INF 1000000000
using namespace std;
int n; // 바구니 위치의 수
int p[301]; // 바구니 위치
int m; // 바구니당 들어있는 사탕의 개수

// L[i][j][k] = p[i~j] 위치에 있는 바구니들을 들렀고, 추가로 k개의 바구니를 더 들르려고 할 때 방문한 바구니들에서 없어지는 사탕의 합의 최소값 (현재 p[i]에 위치)
int L[303][303][303];
// R[i][j][k] = p[i~j] 위치에 있는 바구니들을 들렀고, 추가로 k개의 바구니를 더 들르려고 할 때 방문한 바구니들에서 없어지는 사탕의 합의 최소값 (현재 p[j]에 위치)
int R[303][303][303];

int min2(int a, int b){
	return a<b?a:b;
}
int max2(int a, int b){
	return a>b?a:b;
}

// lostCandy(s,e,k,true) : L[s][e][k] 값 계산
// lostCandy(s,e,k,false) : R[s][e][k] 값 계산

int lostCandy(int s, int e, int k, bool left){
	if(left){
		if(L[s][e][k]>=0) return L[s][e][k];
		if(k==0) return 0;

		int ret=INF;
		if(s-1>=0) ret=min2(ret, lostCandy(s-1,e,k-1,true) + (p[s]-p[s-1])*k );
		if(e+1<n) ret=min2(ret, lostCandy(s,e+1,k-1,false) + (p[e+1]-p[s])*k );

		return (L[s][e][k]=ret);
	}
	else{
		if(R[s][e][k]>=0) return R[s][e][k];
		if(k==0) return 0;

		int ret=INF;
		if(s-1>=0) ret=min2(ret, lostCandy(s-1,e,k-1,true) + (p[e]-p[s-1])*k );
		if(e+1<n) ret=min2(ret, lostCandy(s,e+1,k-1,false) + (p[e+1]-p[e])*k );

		return (R[s][e][k]=ret);
	}
}

int main(void){

	// 입력
	scanf("%d %d",&n,&m);
	for(int i=0; i<n; i++) scanf("%d",&p[i]);

	p[n++]=0; // 원점을 추가
	sort(p,p+n);
	
	int s; // 시작 인덱스
	for(int i=0; i<n; i++)
		if(p[i]==0) {s=i; break;}

	// L,R 초기화
	for(int i=0; i<=n; i++)
		for(int j=0; j<=n; j++)
			for(int k=0; k<=n; k++)
				L[i][j][k]=R[i][j][k]=-1;

	int ans=0;
	// i개 바구니에 있는 사탕을 먹는 경우
	for(int i=0; i<n; i++) // n은 원점을 포함한 위치의 개수이므로 n-1개 바구니까지 들를 수 있음
		ans=max2(ans,m*i-lostCandy(s,s,i,true));

	// 출력
	printf("%d\n",ans);
	return 0;
}
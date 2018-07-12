#include <cstdio>
#include <algorithm>
#include <functional>
#define MIN_k -50000
#define MAX_k 50000*10

#define MEM_OPT 1
using namespace std;
typedef long long ll;
int N; // 선분의 개수(1~N번 선분)
int K; // 필요한 선분의 개수 (K각형을 만들어야 함)
int A[51]; // A[i] = i번 선분의 길이

// D[i][j][k+50000] = 길이값으로 내림차순 정렬된 상태에서 1~i번 선분으로부터 j개의 선분을 선택하였을 때,
// (선택된 선분들 중 가장 긴 선분을 제외한 (j-1)개의 선분 길이 합 - 선택된 선분들 중 가장 긴 선분의 길이) = k 인 경우의 수
#if MEM_OPT
ll D[2][11][MAX_k-MIN_k+1];
#else
ll D[51][11][MAX_k-MIN_k+1];
#endif

int main(void){

	// 입력
	scanf("%d",&N);
	for(int i=1; i<=N; i++) scanf("%d",&A[i]);
	scanf("%d",&K);

	// A 배열을 내림차순으로 정렬
	sort(A+1,A+N+1,greater<int>());

#if MEM_OPT
	// D 배열 계산 (DP 수행)
	D[0][0][0+50000] = 1; // base case
	for(int i=1; i<=N; i++){
		int curIdx=i%2, oldIdx=1-i%2;
		for(int j=0; j<=K; j++){
			for(int k=MIN_k; k<=MAX_k; k++){
				if(j==0) D[curIdx][j][k+50000] = D[oldIdx][j][k+50000];
				else if(j==1){
					if(k+50000+A[i]<=MAX_k) D[curIdx][j][k+50000] = D[oldIdx][j-1][k+50000+A[i]] + D[oldIdx][j][k+50000];
					else D[curIdx][j][k+50000] = D[oldIdx][j][k+50000];
				}
				else D[curIdx][j][k+50000] = D[oldIdx][j-1][k+50000-A[i]] + D[oldIdx][j][k+50000];
			}
		}
	}
	// 답 구하기
	ll ans=0;
	for(int k=1; k<=MAX_k; k++)
		ans+=D[N%2][K][k+50000];
	printf("%lld\n",ans);
#else
	// D 배열 계산 (DP 수행)
	D[0][0][0+50000] = 1; // base case
	for(int i=1; i<=N; i++){
		for(int j=0; j<=K; j++){
			for(int k=MIN_k; k<=MAX_k; k++){
				if(j==0) D[i][j][k+50000] = D[i-1][j][k+50000];
				else if(j==1){
					if(k+50000+A[i]<=MAX_k) D[i][j][k+50000] = D[i-1][j-1][k+50000+A[i]] + D[i-1][j][k+50000];
					else D[i][j][k+50000] = D[i-1][j][k+50000];
				}
				else D[i][j][k+50000] = D[i-1][j-1][k+50000-A[i]] + D[i-1][j][k+50000];
			}
		}
	}
	// 답 구하기
	ll ans=0;
	for(int k=1; k<=MAX_k; k++)
		ans+=D[N][K][k+50000];
	printf("%lld\n",ans);
#endif
	return 0;
}
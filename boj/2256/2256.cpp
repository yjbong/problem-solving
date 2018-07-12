#include <cstdio>
#include <algorithm>
#include <functional>
#define INF 1000000000000000000ll
using namespace std;
typedef long long ll;
int K; // 만들어야 하는 젓가락 세트 수
int N; // 젓가락의 수

ll H[5001]; // H[i] = i번 젓가락의 길이
ll D[5001][1001]; // D[i][j] = 1~i번 젓가락에서 K개 세트를 만들때 최소 벌점
ll min2(ll a, ll b){ return a<b?a:b; }
int main(void){
	scanf("%d %d",&K,&N);
	for(int i=1; i<=N; i++) scanf("%lld",&H[i]);
	sort(H+1,H+N+1,greater<ll>() ); // H를 내림차순 정렬

	// 초기화
	for(int i=0; i<=N; i++) D[i][0]=0;
	for(int i=0; i<=N; i++)
		for(int j=1; j<=K; j++) D[i][j]=INF;

	for(int i=1; i<=N; i++){
		for(int j=1; j<=K && j*3<=i; j++){ // j*3>i 이면 모두 INF로 처리한다
			// case 1 : i번 젓가락이 세트에 포함되지 않음
			D[i][j]=min2(D[i][j], D[i-1][j]);
			// case 2 : i와 i-1번 젓가락이 세트에 포함 (가장 큰 젓가락 없이)
			if(i>1) D[i][j]=min2(D[i][j], D[i-2][j-1]+(H[i]-H[i-1])*(H[i]-H[i-1]));
			// case 3 : i, i-1, i-2번 젓가락이 세트에 포함 (완전한 세트)
			if(i>2) D[i][j]=min2(D[i][j], D[i-3][j-1]+(H[i]-H[i-1])*(H[i]-H[i-1]));
		}
	}
	printf("%lld\n",D[N][K]);
	return 0;
}
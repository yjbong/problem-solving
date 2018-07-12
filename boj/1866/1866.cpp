#include <cstdio>
#include <algorithm>
#define INF 1111111111
using namespace std;
typedef long long ll;

int N; // 배송해야 할 물품의 개수
ll T; // 트럭을 1만큼 이동시키는데 드는 비용
ll H; // 헬리콥터 1회 사용 비용
ll p[3000]; // p[i] = i번째 배송할 물품의 위치
ll d[3000]; // d[i] = p[1~i]까지 배송 완료했을 때의 최소 비용
ll s[3000]; // s[i] = p[1]부터 p[i]까지의 합


ll rangeSum(int start, int end){ // return p[start]+...+p[end]
	int ret=0;
	if(end>=0) ret+=s[end];
	if(start>=1) ret-=s[start-1];
	return ret;
}

ll min2(ll a, ll b){
	return a<b?a:b;
}

int main(void){

	scanf("%d",&N);
	for(int i=0; i<N; i++) scanf("%lld",&p[i]);
	scanf("%lld %lld",&T,&H);
	sort(p,p+N);

	// s배열 계산
	s[0]=p[0];
	for(int i=1; i<N; i++) s[i]=s[i-1]+p[i];
	
	// DP
	for(int i=0; i<N; i++) d[i]=INF;
	for(int i=0; i<N; i++){
		for(int j=0; j<=i; j++){ // d[i]=d[j-1] + (p[j ~ i] 구간을 배송하는 최소 비용)

			// p[j ~ i] 구간을 배송하는 최소 비용 계산

			// case 1: 헬리콥터 1회 사용
			ll cost1=H;
			ll hPos=(j+i)/2; // 헬리콥터는 p[j ~ i] 구간의 중간 지점인 p[(j+i)/2] 에 착륙해야 최적

			// 헬리콥터 착륙 지점에서 출발하여 p[j ~ i] 구간에 배송하기 위한 트럭 비용 추가
			cost1+=(p[hPos]*(hPos-j))*T;
			cost1-=rangeSum(j,hPos-1)*T;
			cost1+=rangeSum(hPos+1,i)*T;
			cost1-=(p[hPos]*(i-hPos))*T;

			// case 2: 헬리콥터 사용 안하는 경우(트럭이 원점에서 출발)
			ll cost2=rangeSum(j,i)*T;

			// curCost = p[j ~ i] 구간의 최소 배송 비용
			ll curCost=min2(cost1,cost2);
			if(j>=1) curCost+=d[j-1];

			// d[i] 업데이트
			if(d[i]>curCost) d[i]=curCost;
		}
	}

	// 답 출력
	printf("%lld\n",d[N-1]);
	return 0;
}
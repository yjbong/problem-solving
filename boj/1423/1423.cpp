#include <cstdio>
typedef long long ll;
int n; // max level
ll q[50]; // q[i] = # of i-level characters
ll p[50]; // p[i] = power of a i-level character
int days; // total training days

ll cache[50][101][101];

ll max2(ll a, ll b){ return a>b?a:b; }
ll min2(ll a, ll b){ return a<b?a:b; }

// maxGainPower(curLev, days, fromOldLev)
// 현재 고려 중인 레벨이 curLev, 남은 훈련 일수가 days, 이전 레벨에서 현재 레벨로 업그레이드된 캐릭터가 fromOldLev개일 때,
// 앞으로 적절히 훈련을 시켜서 추가로 얻을 수 있는 최대 힘의 합
ll maxGainPower(int curLev, int days, int fromOldLev){

	if(curLev==n-1) return 0;
	else if(cache[curLev][days][fromOldLev]>=0) return cache[curLev][days][fromOldLev]; // memoization
	
	ll ret=0;
	// curLev 에서 다음 레벨로 업그레이드할 캐릭터가 i개
	// (이전 레벨(curLev-1)에서 업그레이드되어 현재 레벨이 된 캐릭터도 고려 대상)
	for(ll i=0; i<=min2(days,q[curLev]+fromOldLev); i++)
		ret=max2(ret, maxGainPower(curLev+1, days-i, i) + (p[curLev+1]-p[curLev])*i);
	
	return (cache[curLev][days][fromOldLev]=ret);
}

int main(void){

	// input
	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%lld",&q[i]);
	for(int i=0; i<n; i++) scanf("%lld",&p[i]);

	ll sum=0;
	for(int i=0; i<n; i++) sum+=q[i]*p[i];

	scanf("%d",&days);

	// init cache
	for(int i=0; i<50; i++)
	for(int j=0; j<=100; j++)
	for(int k=0; k<=100; k++)
		cache[i][j][k]=-1;

	// output
	ll ans=maxGainPower(0,days,0);
	printf("%lld\n",sum+ans);
	return 0;
}
#include <cstdio>
typedef long long ll;
ll N; // 그림의 크기(N*N)
ll K; // 제거한 타일의 수
ll min2(ll a, ll b){ return a<b?a:b; }
ll max2(ll a, ll b){ return a>b?a:b; }

// (x,y) 위치의 색상
ll color(ll x, ll y){
	ll group=min2(min2(x,y),N-(max2(x,y)-1));
	return (group%3?group%3:3);
}

int main(void){
	scanf("%lld %lld",&N,&K);
	for(ll i=0; i<K; i++){
		ll a,b;
		scanf("%lld %lld",&a,&b);
		printf("%lld\n",color(a,b));
	}
	return 0;
}
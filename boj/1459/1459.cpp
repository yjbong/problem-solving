#include <cstdio>
typedef long long ll;

ll min2(ll a, ll b){ return a<b?a:b; }
ll max2(ll a, ll b){ return a>b?a:b; }
int main(void){

	ll x, y, w, s;
	scanf("%lld %lld %lld %lld",&x, &y, &w, &s);

	ll sol=0;
	if(s<w*2) sol+=min2(x,y)*s;
	else sol+=min2(x,y)*w*2;

	if(s<w) sol+=((max2(x,y)-min2(x,y))/2)*2*s;
	else sol+=((max2(x,y)-min2(x,y))/2)*2*w;

	sol+=((max2(x,y)-min2(x,y))%2)*w;
	printf("%lld\n",sol);
	return 0;
}
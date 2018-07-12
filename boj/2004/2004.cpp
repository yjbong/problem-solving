#include <cstdio>
typedef long long ll;
ll twos;
ll fives;
ll n,m,tmp;
int main(void){

	scanf("%lld %lld",&n,&m);

	// from (n!)
	tmp=n;
	while(tmp>0){ twos+=tmp/2; tmp/=2; }
	tmp=n;
	while(tmp>0){ fives+=tmp/5; tmp/=5; }

	// from (m!)
	tmp=m;
	while(tmp>0){ twos-=tmp/2; tmp/=2; }
	tmp=m;
	while(tmp>0){ fives-=tmp/5; tmp/=5; }

	// from (n-m!)
	tmp=n-m;
	while(tmp>0){ twos-=tmp/2; tmp/=2; }
	tmp=n-m;
	while(tmp>0){ fives-=tmp/5; tmp/=5; }

	ll ans=twos<fives?twos:fives;
	printf("%lld\n",ans);
	return 0;
}
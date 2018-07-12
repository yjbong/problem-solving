#include <cstdio>
typedef long long ll;
int main(void){
	ll a,b,c,d;
	scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
	ll bdgts=0,ddgts=0,tmp;

	tmp=b;
	while(tmp>0){ tmp/=10; bdgts++; }
	tmp=d;
	while(tmp>0){ tmp/=10; ddgts++; }

	for(int i=0; i<bdgts; i++) a*=10;
	for(int i=0; i<ddgts; i++) c*=10;

	printf("%lld\n",a+b+c+d);
	return 0;
}
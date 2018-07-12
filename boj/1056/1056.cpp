#include <cstdio>
#include <map>
#define MAX_N 1000000000000000000ll
using namespace std;
typedef long long ll;
map <ll,ll> cache;

ll min2(ll a, ll b){ return a<b?a:b; }
ll abs2(ll a){ return a<0?(-a):a; }

ll getRight(int exponent){

	if(exponent>=59) return 1;
	else if(exponent>=38) return 2;
	else if(exponent>=30) return 3;
	else if(exponent>=26) return 4;
	else if(exponent>=24) return 5;
	else if(exponent>=22) return 6;
	else if(exponent>=20) return 7;
	else if(exponent==19) return 8;
	else if(exponent==18) return 10;
	else if(exponent==17) return 11;
	else if(exponent==16) return 13;
	else if(exponent==15) return 15;
	else if(exponent==14) return 19;
	else if(exponent==13) return 24;
	else if(exponent==12) return 31;
	else if(exponent==11) return 43;
	else if(exponent==10) return 63;
	else if(exponent==9) return 100;
	else if(exponent==8) return 177;
	else if(exponent==7) return 372;
	else if(exponent==6) return 1000;
	else if(exponent==5) return 3981;
	else if(exponent==4) return 31622;
	else if(exponent==3) return 1000000;
	else if(exponent==2) return 1000000000;
	else return -1;
}

ll minStep(ll num){
	if(num==1) return 0;
	else if(cache.find(num)!=cache.end()) return cache.find(num)->second;
	else{
		ll ans=num-1;

		for(int i=2; i<=60; i++){
			ll left=1, right=getRight(i);

			ll result=0;
			while(left<=right){
				
				ll mid=(left+right)/2;

				ll tmp=1;
				for(int j=0; j<i; j++) tmp*=mid;

				if(tmp>num) right=mid-1;
				else if(tmp<num){
					left=mid+1;
					if(result<mid) result=mid;
				}
				else{
					result=mid;
					break;
				}
			}

			ll resultPow=1, resultPlusOnePow=1;
			for(int j=0; j<i; j++) resultPow *= result;
			for(int j=0; j<i; j++) resultPlusOnePow *= (result+1);

			if(result<num) ans=min2(ans, minStep(result)+abs2(num-resultPow)+1);
			if(result+1<num) ans=min2(ans, minStep(result+1)+abs2(num-resultPlusOnePow)+1);
		}

		cache.insert(make_pair(num, ans));
		return ans;
	}
}

int main(void){
	
	ll n;
	scanf("%lld",&n);
	printf("%lld\n", minStep(n));

	return 0;
}
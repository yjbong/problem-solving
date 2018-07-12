#include <cstdio>
typedef long long ll;
typedef struct{
	ll ja; // 분자
	ll mo; // 분모
}FRAC;
ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}
ll lcm(ll a, ll b){
	return (a*b)/gcd(a,b);
}

// return a-b
FRAC subtract(FRAC a, FRAC b){
	ll commonMo=lcm(a.mo,b.mo);
	ll ja=a.ja*(commonMo/a.mo)-b.ja*(commonMo/b.mo);
	bool minus=false;
	if(ja<0){ minus=true; ja=-ja; }

	ll curGcd=gcd(ja,commonMo);
	ja/=curGcd, commonMo/=curGcd;

	if(minus) ja=-ja;

	FRAC result;
	result.ja=ja; result.mo=commonMo;
	return result;
}

int main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		FRAC input;
		scanf("%lld %lld",&input.ja,&input.mo);

		bool go;
		ll ans;
		do{
			go=true;
			ll left=1ll, right=2147483647ll;
			ll curAns=right;
			while(left<=right){
				ll mid=(left+right)/2;
				FRAC curFrac;
				curFrac.ja=1ll, curFrac.mo=mid;

				FRAC curResult=subtract(input,curFrac);
				if(curResult.ja<0){
					left=mid+1;	
				}
				else if(curResult.ja>0){
					if(curAns>mid) curAns=mid;
					right=mid-1;
				}
				else{
					if(curAns>mid) curAns=mid;
					go=false;
					break;
				}
			}
			FRAC frac;
			frac.ja=1ll, frac.mo=curAns;
			input=subtract(input,frac);

			ans=frac.mo;
		}while(go);

		printf("%lld\n",ans);
	}
	return 0;
}
#include <cstdio>
#include <cmath>
#define INF 1000000000000ll
typedef long long ll;
ll gcd,lcm;
ll ansPair[2];
ll getGcd(ll a, ll b){
    if (b==0) return a;
    return getGcd(b, a%b);
}
int main(void){
	scanf("%lld %lld",&gcd,&lcm);
	if(lcm%gcd==0){
		ll num=lcm/gcd;

		ll sqNum=0;
		ll left=1, right=num;
		while(left<=right){
			ll mid=(left+right)/2;
			if(mid*mid<=num){
				if(sqNum<mid) sqNum=mid;
				left=mid+1;
			}
			else right=mid-1;
		}

		ll curSum=INF;
		for(int i=1; i<=sqNum+1; i++){
			if(num%i==0 && getGcd(i,num/i)==1){
				if(i+(num/i)<curSum){
					curSum=i+(num/i);
					ansPair[0]=i;
					ansPair[1]=num/i;
				}
			}
		}

		ansPair[0]*=gcd;
		ansPair[1]*=gcd;
		if(ansPair[0]>ansPair[1]){
			ll tmp;
			tmp=ansPair[0];
			ansPair[0]=ansPair[1];
			ansPair[1]=tmp;
		}
		printf("%lld %lld\n",ansPair[0],ansPair[1]);
	}
	return 0;
}
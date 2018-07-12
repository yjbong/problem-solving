#include <cstdio>
int t,n;
int pow2,pow3,pow5,pow7;
int min2(int a, int b){ return a<b?a:b; }
int main(void){

	scanf("%d",&t);
	while(t--){
		pow2=pow3=pow5=pow7=0;
		scanf("%d",&n);
		if(n==1){ printf("1\n"); continue; }

		while(n%2==0){ pow2++; n/=2; }
		while(n%3==0){ pow3++; n/=3; }
		while(n%5==0){ pow5++; n/=5; }
		while(n%7==0){ pow7++; n/=7; }

		int ans=0;
		if(n>=10){ printf("-1\n"); continue; }
		
		// 3*3 -> 9
		ans += pow3/2;
		pow3 = pow3%2;
		// 2*2*2 -> 8
		ans += pow2/3;
		pow2 = pow2%3;
		// 2*3 -> 6
		int tmp = min2(pow2, pow3);
		ans += tmp;
		pow2 -=	tmp;
		pow3 -= tmp;
		// 2*2 -> 4
		ans += pow2/2;
		pow2 = pow2%2;
	
		// add rest
		ans += pow2;
		ans += pow3;
		ans += pow5;
		ans += pow7;
		
		printf("%d\n",ans);
	}
	return 0;
}
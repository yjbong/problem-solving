#include <cstdio>
int n;
bool isNotPrime[123456*2+1];
int main(void){
	isNotPrime[0]=isNotPrime[1]=true;
	for(int i=2; i<=123456*2; i++)
		if(!isNotPrime[i])
			for(int j=i*2; j<=123456*2; j+=i) isNotPrime[j]=true;
	while(1){
		scanf("%d",&n);
		if(n==0) break;
		int primes=0;
		for(int i=n+1; i<=2*n; i++)
			if(!isNotPrime[i]) primes++;
		printf("%d\n",primes);
	}
	return 0;
}
#include <cstdio>
long long fib[91];
int main(void){
	fib[0]=0; fib[1]=1;
	for(int i=2; i<=90; i++) fib[i]=fib[i-1]+fib[i-2];
	int n;
	scanf("%d",&n);
	printf("%lld\n",fib[n]);
	return 0;
}
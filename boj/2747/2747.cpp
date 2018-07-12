#include <cstdio>
int n;
long long f[46];
int main(void){
	f[0]=0; f[1]=1;
	for(int i=2; i<=45; i++) f[i]=f[i-1]+f[i-2];
	scanf("%d",&n);
	printf("%lld\n",f[n]);
	return 0;
}
#include <cstdio>
#include <algorithm>
int N;
long long tip[100000];
int main(void){
	scanf("%d",&N);
	for(int i=0; i<N; i++) scanf("%lld",&tip[i]);
	std::sort(tip,tip+N);
	long long ans=0;
	for(int i=N-1, j=0; i>=0; i--,j++)
		if(tip[i]-j>0) ans+=tip[i]-j;
	printf("%lld\n",ans);
	return 0;
}
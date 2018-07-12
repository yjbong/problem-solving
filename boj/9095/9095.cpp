#include <cstdio>
int d[12]; // d[i] = i를 1,2,3의 합으로 나타내는 방법의 수
int t,n;
int main(void){
	d[0]=0; d[1]=1; d[2]=2; d[3]=4;
	for(int i=4; i<=11; i++) d[i]=d[i-1]+d[i-2]+d[i-3];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%d\n",d[n]);
	}
	return 0;
}
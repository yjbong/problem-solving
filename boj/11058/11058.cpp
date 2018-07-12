#include <cstdio>
typedef long long ll;
int n;
ll d[111]; // 크리보드의 버튼을 i번 눌러서 화면에 출력할 수 있는 A개수의 최대값
ll max2(ll a, ll b){ return a>b?a:b; }
int main(void){	
	scanf("%d",&n);
	d[0]=0;
	for(int i=1; i<=n; i++){
		d[i]=max2(d[i],d[i-1]+1);
		for(int j=1; j<=i-2; j++) d[i]=max2(d[i], d[i-(2+j)]*(j+1));
	}
	printf("%lld\n",d[n]);
	return 0;
}
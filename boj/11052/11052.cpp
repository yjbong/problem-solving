#include <cstdio>
int n; // 붕어빵의 개수
int p[1001]; // p[i] = 붕어빵 i개를 세트로 팔때의 가격
int d[1001]; // d[i] = 붕어빵 i개를 팔아서 얻을 수 있는 최대 이익
int max2(int a, int b){ return a>b?a:b; }
int main(void){
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",&p[i]);
	for(int i=1; i<=n; i++)
		for(int j=0; j<=i; j++)
			d[i]=max2(d[i],d[i-j]+p[j]);
	printf("%d\n",d[n]);
	return 0;
}
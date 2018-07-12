#include <cstdio>
#define MOD 987654321ll
typedef long long ll;
int n; // 사람의 수(짝수)
ll cat[5001]; // cat[i] = i번째 카탈란 수

int main(void){
    
	scanf("%d",&n);
	cat[0]=1;
	for(int i=1; i<=n/2; i++)
		for(int j=0; j<i; j++)
			cat[i]=(cat[i]+(cat[j]*cat[i-1-j])%MOD)%MOD;

	printf("%lld\n",cat[n/2]);
	return 0;
}
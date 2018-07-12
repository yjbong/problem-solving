#include <cstdio>
#define MOD 1000000007
typedef long long ll;
int n, l, r;
ll d[111][111][111]; // [N ~ i]층 건물이 있을 때 왼쪽에서 j개, 오른쪽에서 k개가 보이는 건물 배치의 수
int main(void){

	scanf("%d %d %d", &n,&l,&r);
	d[n][1][1] = 1;
	for (int i = n - 1; i >= 1; i--)
		for (int j = 1; j <= n - i + 1; j++)
			for (int k = 1; k <= n - i + 1; k++)
				if (j + k <= n - i + 2)
					d[i][j][k] = (d[i + 1][j][k] * (n - (i + 1)) + d[i + 1][j - 1][k] + d[i + 1][j][k - 1])%MOD;
	
	printf("%lld\n", d[1][l][r]);
	return 0;
}
#include <cstdio>
#define INF 1000000

int min2(int a, int b){
	return a < b ? a : b;
}
int w[111][111];
int d[111][111];
int dist[111];

int main(void){
	int n, m;
	scanf("%d %d", &n,&m); // n: 사람 수, m: 친구관계 수
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
		w[i][j] = INF;

	for (int i = 1; i <= m; i++){
		int from, to;
		scanf("%d %d", &from, &to);
		w[from][to] = w[to][from] = 1;
	}

	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
		d[i][j] = (i == j ? 0 : w[i][j]);

	for (int k = 1; k <= n; k++)
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
		d[i][j] = min2(d[i][j], d[i][k] + d[k][j]);

	int ans = -1;
	for (int i = 1; i <= n; i++){
		dist[i] = 0;
		for (int j = 1; j <= n; j++)
		if (i != j) dist[i] += d[i][j];
		if (ans<0 || dist[ans]>dist[i]) ans = i;
	}
	printf("%d\n",ans);
	return 0;
}
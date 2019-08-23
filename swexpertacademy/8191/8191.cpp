#include <cstdio>
int T, N, S[200001], O[200001];
int main() {
	scanf("%d", &T);
	for (int z = 1; z <= T; z++) {
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) { scanf("%d", &S[i]); O[S[i]] = i; }
		int ans = 1;
		for (int i = 1; i<N; i++) if (O[i + 1]<O[i]) ans++;
		printf("#%d %d\n", z, ans);
	}
	return 0;
}
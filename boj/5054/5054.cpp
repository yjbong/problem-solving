#include <cstdio>
int t;
int n;
int x[20];
int main(void) {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &x[i]);
		int maxX = -1, minX = 100;
		for (int i = 0; i < n; i++) {
			if (maxX < x[i]) maxX = x[i];
			if (minX > x[i]) minX = x[i];
		}
		int ans = (maxX - minX) * 2;
		printf("%d\n", ans);
	}
	return 0;
}
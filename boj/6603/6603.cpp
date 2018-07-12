#include <cstdio>
int ans[6];
int k;
int s[13];
void go(int picks, int lastPick) {
	if (picks == 6) {
		for (int i = 0; i < 6; i++) printf("%d ", ans[i]);
		printf("\n");
		return;
	}
	for (int i = lastPick + 1; i < k; i++) {
		ans[picks] = s[i];
		go(picks + 1, i);
	}
}
int main(void) {
	while (1) {
		scanf("%d", &k);
		if (k == 0) break;
		for (int i = 0; i < k; i++) scanf("%d", &s[i]);
		go(0, -1);
		printf("\n");
	}
	return 0;
}
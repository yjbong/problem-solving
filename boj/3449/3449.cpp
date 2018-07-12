#include <cstdio>
#include <cstring>
int T;
char bin0[101];
char bin1[101];
int main(void) {
	scanf("%d", &T);
	while (T--) {
		scanf("%s", bin0);
		scanf("%s", bin1);

		int len = strlen(bin0);
		int ans = 0;
		for (int i = 0; i < len; i++)
			if (bin0[i] != bin1[i]) ans++;

		printf("Hamming distance is %d.\n", ans);
	}
	return 0;
}
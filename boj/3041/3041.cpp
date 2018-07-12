#include <cstdio>
#include <cstdlib>
char puzzle[4][4 + 1];
int main(void) {

	int ans = 0;
	for (int i = 0; i < 4; i++) scanf("%s", puzzle[i]);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (puzzle[i][j] == '.') continue;
			int idx = puzzle[i][j] - 'A';
			ans += abs(idx / 4 - i) + abs(idx % 4 - j);
		}
	}
	printf("%d\n", ans);
	return 0;
}
#include <cstdio>
#include <cstring>
#define MAXN 8
int N; // 여행할 국가의 수
char nation[MAXN][20];
int main(void) {

	scanf("%d\n", &N);
	for (int i = 0; i < N; i++) scanf("%s", nation[i]);

	bool southAfrica = false;
	int cost = 0;
	for (int i = 0; i < N; i++) {
		if (strcmp(nation[i], "botswana") == 0);
		else if (strcmp(nation[i], "ethiopia") == 0) cost += 50;
		else if (strcmp(nation[i], "kenya") == 0) cost += 50;
		else if (strcmp(nation[i], "namibia") == 0) cost += (southAfrica ? 40 : 140);
		else if (strcmp(nation[i], "south-africa") == 0) southAfrica = true;
		else if (strcmp(nation[i], "tanzania") == 0) cost += 50;
		else if (strcmp(nation[i], "zambia") == 0) {
			if (i + 1 < N && (strcmp(nation[i + 1], "zimbabwe") == 0)) { cost += 50; i++; }
			else cost += 50;
		}
		else if (strcmp(nation[i], "zimbabwe") == 0) {
			if (i + 1 < N && (strcmp(nation[i + 1], "zambia") == 0)) { cost += 50; i++; }
			else cost += 30;
		}
	}

	printf("%d\n", cost);

	return 0;
}
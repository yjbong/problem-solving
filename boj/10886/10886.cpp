#include <cstdio>
int N;
int vote;
int main(void) {
	scanf("%d", &N);
	vote = 0;
	for (int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);
		vote += a ? 1 : -1;
	}
	if (vote > 0) printf("Junhee is cute!\n");
	else printf("Junhee is not cute!\n");
	return 0;
}
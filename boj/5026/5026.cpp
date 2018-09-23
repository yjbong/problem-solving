#include <cstdio>
#include <cstring>
int N; // 문제의 개수
int main(void) {
	scanf("%d\n", &N);
	while (N--) {
		char s[11];
		scanf("%[^\n]\n", s);
		if (s[0] >= '0' && s[0] <= '9') {
			int num0 = 0;
			int i;
			for (i = 0; s[i] != '+'; i++) {
				num0 *= 10;
				num0 += s[i] - '0';
			}
			int num1 = 0;
			for (i = i + 1; i < strlen(s); i++) {
				num1 *= 10;
				num1 += s[i] - '0';
			}
			printf("%d\n", num0 + num1);
		}
		else printf("skipped\n");
	}
	return 0;
}
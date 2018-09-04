#include <cstdio>
#include <cstring>
#define MAXLEN 100
char a[MAXLEN + 1];
char b[MAXLEN + 1];
char op;
int main(void) {
	scanf("%s\n", a);
	scanf("%c\n", &op);
	scanf("%s", b);

	int al = strlen(a), bl = strlen(b);

	if (op == '*') {
		printf("1");
		for (int i = 0; i < al - 1 + bl - 1; i++) printf("0");
		printf("\n");
	}
	else {
		if (al >= bl) {
			a[al - bl]++;
			printf("%s\n", a);
		}
		else {
			b[bl - al]++;
			printf("%s\n", b);
		}
	}

	return 0;
}
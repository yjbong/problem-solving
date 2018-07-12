#include <cstdio>
#include <cstring>
#define MAXLEN 1000000
char input[MAXLEN + 1];
int output[MAXLEN / 3 + 1];
int main(void) {

	scanf("%s", input);

	int inputLen = strlen(input);
	int outputLen = 0;

	for (int i = inputLen - 1; i >= 0; i -= 3) {
		int octa = 0;
		if (i - 2 >= 0 && input[i - 2] == '1') octa += 4;
		if (i - 1 >= 0 && input[i - 1] == '1') octa += 2;
		if (input[i] == '1') octa += 1;
		output[outputLen++] = octa;
	}

	bool nonZero = false;
	for (int i = outputLen - 1; i >= 0; i--) {
		if (nonZero == false && output[i] == 0) {
			if (i == 0) printf("0");
			continue; // ignore leading zero
		}
		nonZero = true;
		printf("%d", output[i]);
	}
	printf("\n");
	return 0;
}
#include <cstdio>
#include <cstring>
char input[101];
double value;
char unit[5];
int main(void) {
	int T;
	scanf("%d\n", &T);
	while (T--) {

		fgets(input, 100, stdin);

		char *tmp;
		tmp = strtok(input, " \n");
		sscanf(tmp, "%lf", &value);

		tmp = strtok(NULL, " \n");
		strcpy(unit, tmp);

		if (!strcmp(unit, "kg")) printf("%.4lf lb\n", value * 2.2046);
		else if (!strcmp(unit, "lb")) printf("%.4lf kg\n", value * 0.4536);
		else if (!strcmp(unit, "l")) printf("%.4lf g\n", value * 0.2642);
		else if (!strcmp(unit, "g")) printf("%.4lf l\n", value * 3.7854);
	}
	return 0;
}
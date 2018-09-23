#include <cstdio>
#include <algorithm>
int a[3];
int main(void) {

	while (1) {
		for (int i = 0; i < 3; i++) scanf("%d", &a[i]);
		if (a[0] == 0 && a[1] == 0 && a[2] == 0) break;
		std::sort(a, a + 3);
		if (a[0] + a[1] <= a[2]) printf("Invalid\n");
		else if (a[0] == a[1] && a[1] == a[2]) printf("Equilateral\n");
		else if (a[0] == a[1] || a[0] == a[2] || a[1] == a[2]) printf("Isosceles\n");
		else printf("Scalene\n");
	}
	return 0;
}
#include <cstdio>
int main(void) {
	int e; // 갖고 있는 빈 병의 수
	int f; // 그날 발견한 빈 병의 수
	int c; // 새 병으로 바꾸는데 필요한 빈 병의 수
	scanf("%d %d %d", &e, &f, &c);
	int bottles = e + f; // 현재 빈 병의 수
	int drinks = 0; // 마신 음료수의 수
	while (bottles >= c) {
		drinks += bottles / c;
		bottles = bottles % c + bottles / c;
	}
	printf("%d\n", drinks);
	return 0;
}
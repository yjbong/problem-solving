#include <cstdio>
#include <cstring>
#include <cstdlib>

char s[101];
char p1[21];
char p2[21];

int main(void) {
	char *tmp;
	scanf("%[^\n]\n", s);
	tmp = strtok(s, " ");
	strcpy(p1, tmp);
	tmp = strtok(NULL, " ");
	strcpy(p2, tmp);

	//printf("player1 = %s\n", p1);
	//printf("player2 = %s\n", p2);

	scanf("%[^\n]\n", s);
	int matches = atoi(s);
	//printf("matches = %d\n", matches);

	for (int i = 0; i < matches; i++) {

		bool isValid = true; // 이번 경기 결과가 올바르면 true

		int p1sets = 0, p2sets = 0; // 각 플레이어가 이긴 세트의 수

		scanf("%[^\n]\n", s);
		int gameNum = 1;
		int p1games, p2games;
		tmp = strtok(s, " ");
		int j;
		p1games = p2games = 0;
		for (j = 0; tmp[j]!=':'; j++) {
			p1games *= 10;
			p1games += tmp[j] - '0';
		}
		for (j++; tmp[j] != '\0'; j++) {
			p2games *= 10;
			p2games += tmp[j] - '0';
		}
		//printf("game %d of match %d = %d:%d\n", gameNum, i, p1games, p2games);

		// 1번째 게임
		if (p1games == 6 && p2games <= 4) {
			p1sets++;
			if (!strcmp(p2, "federer")) isValid = false; // 페더러는 질 수 없음
		}
		else if (p1games == 7 && (p2games == 5 || p2games==6)) {
			p1sets++;
			if (!strcmp(p2, "federer")) isValid = false;
		}
		else if (p1games <= 4 && p2games == 6) {
			p2sets++;
			if (!strcmp(p1, "federer")) isValid = false;
		}
		else if ((p1games == 5 || p1games == 6) && p2games == 7) {
			p2sets++;
			if (!strcmp(p1, "federer")) isValid = false;
		}
		else isValid = false;


		while ((tmp = strtok(NULL, " ")) != NULL) {
			if (p1sets == 2 || p2sets == 2) isValid = false; // 경기의 승자가 이미 정해졌는데 새로운 세트를 하는 것은 잘못된 결과이다.
			
			gameNum++;
			p1games = p2games = 0;
			for (j = 0; tmp[j] != ':'; j++) {
				p1games *= 10;
				p1games += tmp[j] - '0';
			}
			for (j++; tmp[j] != '\0'; j++) {
				p2games *= 10;
				p2games += tmp[j] - '0';
			}
			//printf("game %d of match %d = %d:%d\n", gameNum, i, p1games, p2games);

			// 2번째 게임
			if (gameNum == 2) {
				if (p1games == 6 && p2games <= 4) {
					p1sets++;
					if (!strcmp(p2, "federer")) isValid = false;
				}
				else if (p1games == 7 && (p2games == 5 || p2games == 6)) {
					p1sets++;
					if (!strcmp(p2, "federer")) isValid = false;
				}
				else if (p1games <= 4 && p2games == 6) {
					p2sets++;
					if (!strcmp(p1, "federer")) isValid = false;
				}
				else if ((p1games == 5 || p1games == 6) && p2games == 7) {
					p2sets++;
					if (!strcmp(p1, "federer")) isValid = false;
				}
				else isValid = false;
			}
			else {
				if (p1games == 6 && p2games <= 4) { // 플레이어가 6점이고 상대가 4점 이하
					p1sets++;
					if (!strcmp(p2, "federer")) isValid = false;
				}
				else if (p1games > 6 && p2games==p1games-2) { // 플레이어가 6점보다 많다면, 상대와는 정확히 2점 차이가 나야 함
					p1sets++;
					if (!strcmp(p2, "federer")) isValid = false;
				}
				else if (p1games <= 4 && p2games == 6) {
					p2sets++;
					if (!strcmp(p1, "federer")) isValid = false;
				}
				else if (p1games == p2games - 2 && p2games > 6) {
					p1sets++;
					if (!strcmp(p1, "federer")) isValid = false;
				}
				else isValid = false;
			}
		}

		if (p1sets < 2 && p2sets < 2) isValid = false; // 경기의 승자가 정해지지 않았는데 끝내버린 경우

		// 답 출력
		if (isValid) printf("da\n");
		else printf("ne\n");
	}
	return 0;
}
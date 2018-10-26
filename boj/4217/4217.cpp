#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>
#define MAXH 200
#define MAXW 50
using namespace std;
typedef pair<int, int> ii;
char image[MAXH][MAXW * 4];
int charImage[MAXH][MAXW * 4];
int H;
int W;

int holes[MAXH*MAXW * 4 + 1]; // holes[i] = i��° ���ڰ� ���� ������ ��
int characters;
queue <ii> q;
const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,1,-1 };

int check[MAXH][MAXW * 4];

char ans[MAXH*MAXW * 4 + 1];
int ansLen;

int main(void) {

	int caseNum = 1;
	while (1) {

		// �Է�
		scanf("%d %d\n", &H, &W);
		if (H == 0 && W == 0) break;
		W *= 4;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j += 4) {
				int hex;
				scanf("%1x", &hex);
				for (int k = 0; k < 4; k++)
					image[i][j + k] = hex & (1 << (3 - k)) ? 1 : 0;
			}
		}

		// �ʱ�ȭ
		characters = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				check[i][j] = charImage[i][j] = 0;
			}
		}

		// charImage ���� (���� ���� ���ڿ� ���ϴ� ���� 1, �� ���� ���ڿ� ���ϴ� ���� 2, ... �� ǥ��)
		for (int j = 0; j < W; j++) {
			for (int i = 0; i < H; i++) {
				if (image[i][j]==1 && charImage[i][j]==0) {
					charImage[i][j] = ++characters;
					holes[characters] = 0;

					q.push(make_pair(i, j));
					while (!q.empty()) {
						ii f = q.front(); q.pop();
						int fy = f.first, fx = f.second;
						for (int k = 0; k < 4; k++) {
							int cy = fy + dy[k], cx = fx + dx[k];
							if (cy < 0 || cy >= H || cx < 0 || cx >= W) continue;
							if (image[cy][cx] == 1 && charImage[cy][cx] == 0) {
								charImage[cy][cx] = characters;
								q.push(make_pair(cy, cx));
							}
						}
					}
				}
			}
		}

		// ���ڰ� �ƴ� ������ �����ϸ鼭 �� ������ hole�� �� ������ Ȯ��
		for (int j = 0; j < W; j++) {
			for (int i = 0; i < H; i++) {
				if (charImage[i][j] == 0 && check[i][j] == 0) {
					check[i][j] = 1;
					q.push(make_pair(i, j));
					bool out = false;
					int touchCharNum = 0;
					while (!q.empty()) {
						ii f = q.front(); q.pop();
						int fy = f.first, fx = f.second;

						for (int k = 0; k < 4; k++) {
							int cy = fy + dy[k], cx = fx + dx[k];
							// ���� ���� ���� ��迡 �ִ� ���
							if (cy < 0 || cy >= H || cx < 0 || cx >= W) {
								out = true;
								continue;
							}
							// �ֺ� ���� ���ڿ� ���Ե� ���
							if (charImage[cy][cx] > 0) touchCharNum = charImage[cy][cx];
							// �ֺ� ���� ���� ������Ʈ�� ��ġ�� ���
							else if (check[cy][cx] == 0) {
								check[cy][cx] = 1;
								q.push(make_pair(cy, cx));
							}
						}
					}

					if (out == false && touchCharNum > 0) holes[touchCharNum]++;
				}
			}
		}

		// �� ���
		printf("Case %d: ", caseNum);
		ansLen = 0;
		for (int i = 1; i <= characters; i++) {
			switch (holes[i]) {
			case 0:
				ans[ansLen++] = 'W';
				break;
			case 1:
				ans[ansLen++] = 'A';
				break;
			case 2:
				ans[ansLen++] = 'K';
				break;
			case 3:
				ans[ansLen++] = 'J';
				break;
			case 4:
				ans[ansLen++] = 'S';
				break;
			case 5:
				ans[ansLen++] = 'D';
				break;
			}
		}
		sort(ans, ans + ansLen); // ���ĺ� ������������ ����
		ans[ansLen] = '\0';
		printf("%s\n", ans);
		caseNum++;
	}
	return 0;
}
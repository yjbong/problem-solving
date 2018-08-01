#include <cstdio>
#include <vector>
#define MAXN 500000
using namespace std;

int N; // 수의 길이
int K; // 지워야 하는 숫자의 개수
char num[MAXN + 1];
bool erase[MAXN];

vector <int> pos[10]; // pos[i] = 숫자 i(0~9)가 num에서 등장한 위치의 목록

int min2(int a, int b) { return a < b ? a : b; }
int main(void) {

	scanf("%d %d", &N, &K);
	scanf("%s", num);

	// pos 배열 구하기
	for (int i = 0; i < N; i++) pos[num[i] - '0'].push_back(i);

	
	for (int i = 0; i < N; i++) {

		int nearestBiggerIdx = -1; // 현재 자릿수 바로 뒤부터 K개 자릿수 중, 현재 자릿수보다는 크면서 가장 앞에 있는 숫자의 idx
		for (int j = num[i] - '0' + 1; j < 10; j++) { // 현재 자릿수보다는 큰 숫자들에 대해서,

			// pos 목록에 대한 이분탐색
			int left = 0, right = pos[j].size() - 1;
			while (left <= right) {
				int mid = (left + right) / 2;
				// 찾아야 하는 위치는 i+1 이상, i+K 이하여야 한다.
				if (pos[j][mid] < i + 1) left = mid + 1;
				else if (pos[j][mid] > i + K) right = mid - 1;
				// 찾은 위치가 i+1 이상, i+K 이하인 경우,
				else {
					if (nearestBiggerIdx<0 || nearestBiggerIdx>pos[j][mid]) nearestBiggerIdx = pos[j][mid]; // 필요 시 nearestBiggerIdx 갱신
					right = mid - 1;
				}
			}
		}

		// nearestBiggerIdx를 찾은 경우
		if (nearestBiggerIdx >= 0) {
			// 현재 자릿수를 포함해서 nearestBiggerIdx 직전까지의 모든 자릿수를 지운다.
			for (int j = i; j < nearestBiggerIdx; j++) erase[j] = true;
			// 지워진 자릿수의 개수만큼 K를 소비한다.
			K -= nearestBiggerIdx - i;
			i = nearestBiggerIdx - 1; // 다음 iteration 에서는 이번에 찾은 자릿수(nearestBiggerIdx)를 현재 자릿수로 보고, 같은 동작을 하게 된다.
		}
	}

	// 그래도 K가 남았다면 모두 소비해야 한다. 뒤에서부터 숫자를 지워서 소비한다.
	int idx = N - 1;
	while (K > 0) {
		if (!erase[idx]) { erase[idx] = true; K--; }
		idx--;
	}

	// 지워지고 남은 수를 출력
	for (int i = 0; i < N; i++) if (!erase[i]) printf("%c", num[i]);
	printf("\n");

	return 0;
}
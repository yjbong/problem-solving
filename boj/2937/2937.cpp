#include <cstdio>
#include <vector>
#define INF 1000000000
#define MAXN 100
using namespace std;
int N; // 보드판의 한변의 길이
int M; // 블럭의 개수
vector <int> divisor; // M의 약수 리스트

int A[MAXN][MAXN];
int D[MAXN][MAXN]; // D[i][j] = A배열 중 직사각형 영역 (0,0), (i,j) 의 부분 합

int min2(int a, int b) { return a < b ? a : b; }
int query(int y0, int x0, int y1, int x1) { // (y0,x0), (y1,x1) 직사각형 영역의 부분 합 계산
	if (y0 == 0 && x0 == 0) return D[y1][x1];
	else if (y0 == 0) return D[y1][x1] - D[y1][x0 - 1];
	else if (x0 == 0) return D[y1][x1] - D[y0 - 1][x1];
	else return D[y1][x1] - D[y1][x0 - 1] - D[y0 - 1][x1] + D[y0 - 1][x0 - 1];
}

int main(void) {

	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int R, C;
		scanf("%d %d", &R, &C);
		R--, C--; // 좌표는 0부터 시작하는 것으로 본다.
		if(A[R][C]==0) A[R][C]=1;
	}

	// M의 약수 구하기
	for (int i = 1; i <= M; i++) if (M%i == 0) divisor.push_back(i);

	// D 배열 계산
	D[0][0] = A[0][0];
	for (int i = 1; i < N; i++) D[i][0] = D[i - 1][0] + A[i][0];
	for (int j = 1; j < N; j++) D[0][j] = D[0][j - 1] + A[0][j];
	for (int i = 1; i < N; i++)
		for (int j = 1; j < N; j++)
			D[i][j] = D[i - 1][j] + D[i][j - 1] - D[i - 1][j - 1] + A[i][j];

	// 답 계산
	int ans = INF;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// (i,j)를 왼쪽 위 꼭지점으로 하는 영역
			for (int k = 0; k < divisor.size(); k++) {
				int height = divisor[k], width = M / height;
				
				if (i + height - 1 < N && j + width - 1 < N) {
					ans = min2(ans, height*width - query(i, j, i + height - 1, j + width - 1));
				}
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}
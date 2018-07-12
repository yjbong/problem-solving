#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int x[50000];
int y[50000];
int t[50000];
int max2(int a, int b) { return a > b ? a : b; }
int main(void) {

	// 임의의 두 점 p0 = (a,b), p1 = (c,d)가 있다 하고, 편의상 c>=a 라 생각하자.
	// 그러면 다음 두 가지 경우가 있을 수 있다.
	// 
	// case 1. d>=b 인 경우
	// 두 점의 L1 거리 = (c-a) + (d-b) = (c+d) - (a+b) = (p1의 x좌표 + p1의 y좌표) - (p0의 x좌표 + p0의 y좌표)
	// 
	// case 2. d<b 인 경우
	// 두 점의 L1 거리 = (c-a) + (b-d) = (c-d) - (a-b) = (p1의 x좌표 - p1의 y좌표) - (p0의 x좌표 - p0의 y좌표)
	//
	// 따라서, 1) 입력된 각 좌표들에서 "x좌표 + y좌표" 값을 구하고 그 중 최대값에서 최소값을 뺀다.
	// 그리고 2) 입력된 각 좌표들에서 "x좌표 - y좌표" 값을 구하고 그 중 최대값에서 최소값을 뺀다.
	// 이 때 최대 L1 거리는 1)과 2)에서 구한 값 중 큰 값이다.

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &x[i], &y[i]);

	// case 1에서의 답 구하기
	int ans1;
	for (int i = 0; i < n; i++)
		t[i] = x[i] + y[i];
	sort(t, t + n);
	ans1 = t[n - 1] - t[0];

	// case 2에서의 답 구하기
	int ans2;
	for (int i = 0; i < n; i++)
		t[i] = x[i] - y[i];
	sort(t, t + n);
	ans2 = t[n - 1] - t[0];

	// 답 출력
	printf("%d\n", max2(ans1, ans2));
	return 0;
}
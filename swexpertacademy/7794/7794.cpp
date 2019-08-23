#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int T;
int N; // 쿠폰의 개수
double C; // 게임기의 기존 가격
vector <int> coupon[4]; // coupon[i] = 할인율이 i% 인 쿠폰의 가격 정보
int main() {
	scanf("%d", &T);
	for (int z = 1; z <= T; z++) {
		for (int i = 1; i <= 3; i++) coupon[i].clear();
		scanf("%d %lf", &N, &C);
		for (int i = 0; i<N; i++) {
			int X; // 쿠폰 가격
			int P; // 쿠폰 할인율
			scanf("%d %d", &X, &P);
			coupon[P].push_back(X);
		}
		for (int i = 1; i <= 3; i++)
			sort(coupon[i].begin(), coupon[i].end());

		double ans = C;
		for (int p1 = 0; p1 <= coupon[1].size(); p1++)
			for (int p2 = 0; p2 <= coupon[2].size(); p2++)
				for (int p3 = 0; p3 <= coupon[3].size(); p3++) {
					double cur = C;
					// 할인 적용
					for (int i = 0; i<p1; i++) cur *= 0.99;
					for (int i = 0; i<p2; i++) cur *= 0.98;
					for (int i = 0; i<p3; i++) cur *= 0.97;
					// 쿠폰 비용
					for (int i = 0; i<p1; i++) cur += coupon[1][i];
					for (int i = 0; i<p2; i++) cur += coupon[2][i];
					for (int i = 0; i<p3; i++) cur += coupon[3][i];
					// update ans
					if (ans>cur) ans = cur;
				}
		printf("#%d %.10lf\n", z, ans);
	}
	return 0;
}
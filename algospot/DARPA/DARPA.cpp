#include <cstdio>
#include <algorithm>
#define MAX_DIST 500
using namespace std;
int c, n, m;
double pos[200];
bool possible(double distance) {
	double lastpos = pos[0];
	int cams = 1;
	for (int i = 1; i<m; i++) {
		if (pos[i] - lastpos >= distance) {
			lastpos = pos[i];
			cams++;
			if (cams == n) return true;
		}
	}
	return false;
}

int main(void) {
	scanf("%d", &c);
	while (c--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i<m; i++)
			scanf("%lf", &pos[i]);

		sort(pos, pos + m);

		double ans = 0;
		if (n>1) {
			double left = 0;
			double right = MAX_DIST;
			//while(left<=right){
			for (int i = 0; i<100; i++) {
				double mid = (left + right) / 2;
				if (possible(mid)) {
					if (ans<mid) ans = mid;
					//left=mid+1;
					left = mid;
				}
				else {
					//right=mid-1;
					right = mid;
				}
			}
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}
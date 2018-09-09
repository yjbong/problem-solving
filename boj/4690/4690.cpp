#include <cstdio>
int main(void) {
	for (int a = 2; a <= 100; a++)
	for (int b = 2; a*a*a>=b*b*b; b++)
	for (int c = b; a*a*a>=b*b*b+c*c*c; c++) { // c�� b�̻��̾�� �ϹǷ� �ʱⰪ�� b
		int target = a*a*a - b*b*b - c*c*c;
		int d = -1;
		int left = c, right = 100; // d�� c�̻��̾�� �ϹǷ� left=c �� ����
		while (left <= right) {
			int mid = (left + right) / 2;
			if (target < mid*mid*mid) right = mid - 1;
			else if (target > mid*mid*mid) left = mid + 1;
			else { d = mid; break; }
		}
		if (d >= 0) printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
	}
	return 0;
}
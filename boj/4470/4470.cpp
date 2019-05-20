#include <iostream>
#include <cstring>
int N; // 줄의 수
char A[100 + 1];
using namespace std;
int main(void) {
	cin >> N;
	cin.getline(A, 100);
	for (int i = 1; i <= N; i++) {
		cin.getline(A, 100);
		cout << i << ". " << A << endl;
	}
	return 0;
}
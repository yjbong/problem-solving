#include <iostream>
#include <vector>

using namespace std;

int birthdayCakeCandles(int n, vector <int> ar) {
	// Complete this function
	int h = 0;
	for (int i = 0; i<n; i++) if (h<ar[i]) h = ar[i];
	int ret = 0;
	for (int i = 0; i<n; i++) if (h == ar[i]) ret++;
	return ret;
}

int main() {
	int n;
	cin >> n;
	vector<int> ar(n);
	for (int ar_i = 0; ar_i < n; ar_i++) {
		cin >> ar[ar_i];
	}
	int result = birthdayCakeCandles(n, ar);
	cout << result << endl;
	return 0;
}

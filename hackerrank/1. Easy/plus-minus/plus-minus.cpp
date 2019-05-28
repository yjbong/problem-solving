#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int arr_i = 0; arr_i < n; arr_i++) {
		cin >> arr[arr_i];
	}
	int plus = 0, minus = 0, zero = 0;
	for (int i = 0; i<n; i++) {
		if (arr[i]>0) plus++;
		else if (arr[i]<0) minus++;
		else zero++;
	}
	cout << (double)plus / n << endl;
	cout << (double)minus / n << endl;
	cout << (double)zero / n << endl;
	return 0;
}

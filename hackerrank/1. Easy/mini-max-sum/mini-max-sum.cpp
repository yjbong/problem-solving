#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> arr(5);
	for (int arr_i = 0; arr_i < 5; arr_i++) {
		cin >> arr[arr_i];
	}
	long long min = 1000000001;
	long long max = 0;
	long long sum = 0;
	for (int i = 0; i<5; i++) {
		sum += arr[i];
		if (min>arr[i]) min = arr[i];
		if (max<arr[i]) max = arr[i];
	}
	printf("%lld %lld\n", sum - max, sum - min);
	return 0;
}

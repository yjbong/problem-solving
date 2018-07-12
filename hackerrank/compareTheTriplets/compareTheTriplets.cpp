#include <iostream>
#include <vector>

using namespace std;

vector < int > solve(int a0, int a1, int a2, int b0, int b1, int b2) {
	// Complete this function
	vector <int> ans;
	ans.push_back(0);
	ans.push_back(0);
	if (a0>b0) ans[0]++;
	else if (a0<b0) ans[1]++;

	if (a1>b1) ans[0]++;
	else if (a1<b1) ans[1]++;

	if (a2>b2) ans[0]++;
	else if (a2<b2) ans[1]++;
	return ans;
}

int main() {
	int a0;
	int a1;
	int a2;
	cin >> a0 >> a1 >> a2;
	int b0;
	int b1;
	int b2;
	cin >> b0 >> b1 >> b2;
	vector < int > result = solve(a0, a1, a2, b0, b1, b2);
	for (size_t i = 0; i < result.size(); i++) {
		cout << result[i] << (i != result.size() - 1 ? " " : "");
	}
	cout << endl;


	return 0;
}

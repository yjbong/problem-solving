#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

priority_queue <int> minHeap;
priority_queue <int> maxHeap;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int a_i = 0; a_i < n; a_i++) {
		cin >> a[a_i];
	}

	for (int i = 0; i<n; i++) {
		// 홀수 개인 경우 minHeap의 top값을 median으로 하고자 한다. 짝수 개인 경우는 minHeap과 maxHeap의 top 값의 평균을 median으로 한다.

		// 따라서 minHeap이 비어있으면 무조건 minHeap에 push
		//(음수 기호를 붙여서 넣는 것은 pq를 minimum heap처럼 쓰기 위함. 기본적으로 pq는 maximum heap으로 동작)
		if (minHeap.empty()) minHeap.push(-a[i]);
		// 현재 원소가 minHeap의 top값보다 작다면 maxHeap에 push한다.
		else if (a[i]<(-minHeap.top())) maxHeap.push(a[i]);
		// 현재 원소가 minHeap의 top값보다 크거나 같다면 minHeap에 push한다.
		else minHeap.push(-a[i]);

		// minHeap의 사이즈가 maxHeap 사이즈보다 2 이상 커지면 minHeap의 top이 더 이상 median이 되지 않으므로 minHeap의 top을 maxHeap으로 보내어 균형을 맞춰준다.
		if (minHeap.size()>maxHeap.size() + 1) {
			maxHeap.push(-minHeap.top());
			minHeap.pop();
		}
		// maxHeap의 사이즈가 maxHeap 사이즈보다 1 이상 커지면 minHeap의 top이 더 이상 median이 되지 않으므로 maxHeap의 top을 minHeap으로 보내어 균형을 맞춰준다.
		else if (maxHeap.size()>minHeap.size()) {
			minHeap.push(-maxHeap.top());
			maxHeap.pop();
		}

		double ans;
		// 현재까지 홀수 개의 원소
		if ((i + 1) % 2 == 1) ans = -minHeap.top();
		// 현재까지 짝수 개의 원소
		else ans = (maxHeap.top() + (-minHeap.top()))*0.5;

		printf("%.1lf\n", ans);
	}
	return 0;
}

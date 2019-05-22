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
		// Ȧ�� ���� ��� minHeap�� top���� median���� �ϰ��� �Ѵ�. ¦�� ���� ���� minHeap�� maxHeap�� top ���� ����� median���� �Ѵ�.

		// ���� minHeap�� ��������� ������ minHeap�� push
		//(���� ��ȣ�� �ٿ��� �ִ� ���� pq�� minimum heapó�� ���� ����. �⺻������ pq�� maximum heap���� ����)
		if (minHeap.empty()) minHeap.push(-a[i]);
		// ���� ���Ұ� minHeap�� top������ �۴ٸ� maxHeap�� push�Ѵ�.
		else if (a[i]<(-minHeap.top())) maxHeap.push(a[i]);
		// ���� ���Ұ� minHeap�� top������ ũ�ų� ���ٸ� minHeap�� push�Ѵ�.
		else minHeap.push(-a[i]);

		// minHeap�� ����� maxHeap ������� 2 �̻� Ŀ���� minHeap�� top�� �� �̻� median�� ���� �����Ƿ� minHeap�� top�� maxHeap���� ������ ������ �����ش�.
		if (minHeap.size()>maxHeap.size() + 1) {
			maxHeap.push(-minHeap.top());
			minHeap.pop();
		}
		// maxHeap�� ����� maxHeap ������� 1 �̻� Ŀ���� minHeap�� top�� �� �̻� median�� ���� �����Ƿ� maxHeap�� top�� minHeap���� ������ ������ �����ش�.
		else if (maxHeap.size()>minHeap.size()) {
			minHeap.push(-maxHeap.top());
			maxHeap.pop();
		}

		double ans;
		// ������� Ȧ�� ���� ����
		if ((i + 1) % 2 == 1) ans = -minHeap.top();
		// ������� ¦�� ���� ����
		else ans = (maxHeap.top() + (-minHeap.top()))*0.5;

		printf("%.1lf\n", ans);
	}
	return 0;
}

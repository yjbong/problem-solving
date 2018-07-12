#include <iostream>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
int N;
typedef pair<pair<int, int>, string> data;
data a[100000];

int main(void){
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> a[i].first.first >> a[i].second;
		a[i].first.second=i;
	}
	sort(a,a+N);
	for(int i=0; i<N; i++) cout << a[i].first.first << " " << a[i].second << endl;
	return 0;
}
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;
int n; // 과제 수
typedef pair<int,int> ii; // first: 기한, second: 소요시간
vector <ii> work; // 과제 목록

// isPossibleStart(s) --> s일부터 과제를 한다고 했을 때, 모든 과제의 기한을 만족시킬 수 있다면 true
bool isPossibleStart(int s){

	int curDay = s; // 처음 s일동안 아무것도 안함
	for(int i=0; i<work.size(); i++){
		// 남은 과제 중 기한이 가까운 것부터 한다.
		curDay+=work[i].second;

		// 기한 초과될 경우
		if(curDay>work[i].first) return false;
	}
	return true;
}
int main(void){

	scanf("%d",&n);
	for(int i=0; i<n; i++){
		int d,t;
		scanf("%d %d",&d,&t);
		work.push_back(make_pair(t,d));
	}
	sort(work.begin(), work.end());

	// parametric search	
	int left=0, right=1000000000;
	int ans=0;
	while(left<=right){
		int mid=(left+right)/2;
		if(isPossibleStart(mid)){
			if(ans<mid) ans=mid;
			left=mid+1;
		}
		else right=mid-1;
	}
	printf("%d\n", ans);
	return 0;
}
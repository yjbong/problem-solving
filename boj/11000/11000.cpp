#include <cstdio>
#include <algorithm>
#include <set>
#include <utility>
#include <vector>
using namespace std;
typedef pair <int,int> ii;
int n; // # of lectures
vector <ii> lecture; // lecture[i].first = end time of i-th class
		     // lecture[i].second = start time of i-th class
multiset <int> room; // each room's earliest possible start time

int main(void){

	// input
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		int s,t;
		scanf("%d %d",&s,&t);
		lecture.push_back(make_pair(t,s));
	}

	// increasingly sorting by end time
	// (among lectures with same end time, increasingly sorting by start time)
	sort(lecture.begin(), lecture.end());

	// calc answer (minimum number of rooms needed for every lectures)
	// init answer and room set
	int ans=1;
	room.insert(0);

	for(int i=0; i<n; i++){
		int curStart=lecture[i].second;
		int curEnd=lecture[i].first;

		// more room needed for this lecture (no possible rooms)
		if(curStart < *(room.begin())){
			room.insert(curEnd);
			ans++;
		}

		// use best fit room
		else{
			set<int>::iterator upper;
			upper=room.upper_bound(curStart);
			upper--;

			room.erase(upper);
			room.insert(curEnd);
		}
	}

	printf("%d\n",ans);
	return 0;
}
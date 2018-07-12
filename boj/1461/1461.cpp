#include <cstdio>
#include <vector>
#include <algorithm>
#define INF 1000000000
using namespace std;
int n; // 책의 개수
int m; // 한 번에 들 수 있는 책의 수

vector <int> left; // 원점 기준 왼쪽 책의 위치들
vector <int> right; // 원점 기준 오른쪽 책의 위치들
int max2(int a, int b){ return a>b?a:b; }
int main(void){

	// 입력
	scanf("%d %d",&n,&m);
	for(int i=0; i<n; i++){
		int pos;
		scanf("%d",&pos);
		if(pos<0) left.push_back(-pos); // 왼쪽 위치
		else right.push_back(pos); // 오른쪽 위치
	}

	// 위치 오름차순 정렬
	if(left.size()>0) sort(left.begin(), left.end());
	if(right.size()>0) sort(right.begin(), right.end());

	// 거리 누적 (책을 m권씩 들고 출발했다가 원점으로 되돌아옴)
	int ans=0;
	for(int i=left.size()-1; i>=0; i-=m) ans+=left[i]*2;
	for(int i=right.size()-1; i>=0; i-=m) ans+=right[i]*2;

	// 원점에서 가장 먼 곳은 마지막에 방문하여 되돌아가지 않게 함
	int leftMost=0, rightMost=0;
	if(left.size()>0) leftMost=left[left.size()-1];
	if(right.size()>0) rightMost=right[right.size()-1];
	ans-=max2(leftMost,rightMost);

	// 출력
	printf("%d\n",ans);
	return 0;
}
#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>
#include <stack>
#define MAX_N 300000
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;		// first: 원이 x축(y=0)과 만나는 2개의 점 중 왼쪽 x좌표 (left)
				// second: 원이 x축(y=0)과 만나는 2개의 점 중 오른쪽 x좌표 (right)
typedef pair<int,pair<ll,ll> > iii;	// first = idx, second = ii의 내용

int n; // 원의 개수
vector <ii> circle; // 전체 원의 목록
vector <ii> containedCircle[MAX_N]; // containedCircle[i] = i번 원에 directed contained(직접 포함)된 원들의 목록
stack <iii> stk;

int main(void){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		ll x; // 원의 중심좌표 (x,0)
		ll r; // 원의 반지름
		scanf("%lld %lld",&x,&r);
		circle.push_back(make_pair(x-r,-(x+r))); // right기준으로는 내림차순시키기 위해 임시로 음수 부호를 붙임
	}
	sort(circle.begin(),circle.end()); // 1차: left기준으로 오름차순, 2차: right기준으로 내림차순 정렬
	for(int i=0; i<n; i++) circle[i].second=-circle[i].second; // 정렬 후에 right에 음수 부호를 다시 붙여 원상복구

	for(int i=0; i<n; i++){
		while(!stk.empty()){
			// 스택 탑에 있는 원이 현재 원을 직접 포함하는 경우 (스택 탑의 오른쪽 좌표가 현재 원의 오른쪽 좌표보다 크거나 같은 경우)
			if(stk.top().second.second>=circle[i].second){
				containedCircle[stk.top().first].push_back(circle[i]);
				break;
			}
			else{
				stk.pop();
			}
		}
		stk.push(make_pair(i,circle[i]));
	}

	ll ans=1; // 원이 하나도 없을 때의 영역 개수=1
	for(int i=0; i<n; i++){
		ll diameter=circle[i].second-circle[i].first;
		ll covered=0;
		for(int j=0; j<containedCircle[i].size(); j++){
			covered+=containedCircle[i][j].second-containedCircle[i][j].first;
		}
		if(diameter==covered) ans+=2; // i번 원에 직접 포함된 원들이 빈틈없이 늘어선 경우
		else ans+=1;
	}
	printf("%lld\n",ans);	
	return 0;
}
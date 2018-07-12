#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX_N 10000
using namespace std;
typedef long long ll;

// 주어진 직사각형의 '\'방향 대각선의 정보
typedef struct rect{
	ll xbr,ybr; // 오른쪽 아래 꼭지점의 좌표
	ll xtl,ytl; // 왼쪽 위 꼭지점의 좌표
}RECT;
typedef struct point{
	ll x,y; // x,y 좌표
}POINT;

class comparePoint{
public:
	bool operator() (POINT a,POINT b){ // min heap용 비교 함수
		if(a.y*b.x > b.y*a.x) return true;
		else return false;
	}
};

bool compareRect(RECT a, RECT b);

int N; // 직사각형의 개수
RECT rect[MAX_N]; // 대각선

priority_queue<POINT, vector<POINT>, comparePoint> pq;

bool compareRect(RECT a, RECT b){
	// 1st key: 대각선의 오른쪽 아래 꼭지점(xbr,ybr)과 원점과의 기울기가 작은 순서대로 정렬
	if(a.ybr*b.xbr < b.ybr*a.xbr) return true;
	else if(a.ybr*b.xbr > b.ybr*a.xbr) return false;
	else{
		// 2nd key: 대각선의 왼쪽 위 꼭지점(xtl,ytl)과 원점과의 기울기가 작은 순서대로 정렬
		if(a.ytl*b.xtl < b.ytl*a.xtl) return true;
		else return false;
	}
}

int main(void){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		ll xbl,ybl; // 직사각형의 왼쪽 아래 꼭지점의 좌표
		ll xtr,ytr; // 직사각형의 오른쪽 위 꼭지점의 좌표
		scanf("%lld %lld %lld %lld",&xbl,&ybl,&xtr,&ytr);

		// 입력받은 좌표를 '\'방향으로 바꿔서 저장
		rect[i].xbr=xtr, rect[i].ybr=ybl;
		rect[i].xtl=xbl, rect[i].ytl=ytr;

		// 원점과 (xbr,ybr)과의 기울기를 a, 원점과 (xtl,ytl)과의 기울기를 b라 했을 때,
		// 원점으로부터 a이상 b이하의 기울기로 직선을 그렸을 때 이 직사각형과 교차하므로,
		// 이 직사각형을 구간 [a,b]인 선분으로 생각한다
	}

	// 최대로 많이 겹치는 선분(직사각형)의 개수를 구한다
	sort(rect,rect+N,compareRect); // 원점과 직사각형의 (xbr,ybr)과의 기울기 기준으로 오름차순 정렬
	int ans=0;
	for(int i=0; i<N; i++){
		while(!pq.empty() && ((pq.top().y)*rect[i].xbr < rect[i].ybr*(pq.top().x))){
			// 현재 선분과 겹치지 않는 선분 (어떤 직사각형의 왼쪽 위 좌표(pq.top())와 원점과의 기울기가 현재 직사각형의 오른쪽 아래 좌표와 원점과의 기울기보다 작은 경우)
			// 들을 pq에서 제거
			pq.pop();
		}
		POINT curEndPoint;
		curEndPoint.x=rect[i].xtl, curEndPoint.y=rect[i].ytl; // 왼쪽 위 좌표(선분의 끝점)
		pq.push(curEndPoint);

		// ans 업데이트
		if(ans<pq.size()) ans=pq.size();
	}
	printf("%d\n",ans);
	
	return 0;
}
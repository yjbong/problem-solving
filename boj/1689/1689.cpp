#include <cstdio>
#include <utility>
#include <algorithm>
#include <queue>
#define MAX_N 1000000
using namespace std;
typedef pair<int,int> ii; // first: 시작 좌표, second: 끝나는 좌표
int N; // 선분의 개수
ii line[MAX_N]; // 선분
priority_queue <int> pq;
int main(void){
	scanf("%d",&N);
	for(int i=0; i<N; i++)
		scanf("%d %d",&line[i].first,&line[i].second);

	sort(line,line+N); // 선분의 시작 좌표 기준으로 정렬

	int ans=0;
	for(int i=0; i<N; i++){
		// 현재 선분 line[i]와 겹치지 않는 선분들을 pq에서 제거
		while(!pq.empty() && (-pq.top())<=line[i].first){ // 등호가 들어간 이유는 선분이 끝 점에서만 만나는 것은 겹치는 걸로 치지 않기 때문
			pq.pop();
		}
		pq.push(-line[i].second); // 현재 선분의 끝 점을 pq에 넣는다 (min heap으로 사용하기 위해, 음수 기호를 붙여서 넣는다

		// ans 업데이트
		if(ans<pq.size()) ans=pq.size();
	}
	printf("%d\n",ans);
	return 0;
}
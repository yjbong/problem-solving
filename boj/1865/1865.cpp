#include <cstdio>
#include <utility>
#include <vector>
#define INF 1000000000000000000ll

using namespace std;
typedef long long ll;
typedef pair<pair<ll,ll>,ll> iii;
int TC; // 테스트 케이스 개수
int N; // 지점의 개수
int M; // 도로의 개수
int W; // 웜홀의 개수

vector <iii> edge; // edge[i].first.first = i번 간선의 시작 지점, first.second = 도착 지점, second = 늘거나 줄어드는 시간
ll upper[501]; // upper[i] = 시작점(1)에서 i번 정점으로 가는 최단 거리의 상한

int main(void){
    
	scanf("%d",&TC);
	while(TC--){
		edge.clear();
		scanf("%d %d %d",&N,&M,&W);
		for(int i=0; i<M; i++){
			ll S,E,T;
			scanf("%lld %lld %lld",&S,&E,&T);
			// 도로는 방향이 없음
			edge.push_back(make_pair(make_pair(S,E),T));
			edge.push_back(make_pair(make_pair(E,S),T));
		}
		for(int i=0; i<W; i++){
			ll S,E,T;
			scanf("%lld %lld %lld",&S,&E,&T);
			// 웜홀은 방향이 있음
			edge.push_back(make_pair(make_pair(S,E),-T));
		}

		// 시작 정점을 1번으로 가정
		for(int i=2; i<=N; i++) upper[i]=INF;
		upper[1]=0;
		
		// (N-1)번만큼 모든 간선에 대해 relaxation
		for(int i=1; i<=N-1; i++){
			for(int j=0; j<edge.size(); j++){
				ll curStart=edge[j].first.first;
				ll curEnd=edge[j].first.second;
				ll curTime=edge[j].second;
				if(upper[curEnd]>upper[curStart]+curTime){
					upper[curEnd]=upper[curStart]+curTime;
				}
			}
		}

		// N번째 relaxation 시도
		bool backTime=false;
		for(int j=0; j<edge.size(); j++){
			ll curStart=edge[j].first.first;
			ll curEnd=edge[j].first.second;
			ll curTime=edge[j].second;
			if(upper[curEnd]>upper[curStart]+curTime){
				upper[curEnd]=upper[curStart]+curTime;
				backTime=true; // N번째 시도 중에 relaxation 이 가능하다면 음수 사이클이 존재하는 것임
			}
		}
		if(backTime) printf("YES\n"); // 음수 사이클이 존재하면 가능
		else printf("NO\n");
	}
	return 0;
}
#include <cstdio>
#include <utility>
#include <vector>
#include <queue>
#define MAX_N 10000
#define INF 1000000000
using namespace std;
int N; // 도시의 개수
int M; // 도로의 개수
typedef struct{
	int indegree; // in edge의 개수
	vector <pair<int,int> > outEdgeList; // first: 도착 도시, second: 소요 시간
	vector <pair<int,int> > inEdgeList; // first: 출발 도시, second: 소요 시간
}CITY;

CITY city[MAX_N+1]; // 도시(1~N)
int start; // 시작 도시
int end; // 끝 도시
bool reachable[MAX_N+1]; // reachable[i] = 시작 도시 start에서 i번 도시로 갈 수 있으면 true

int time[MAX_N+1];
int criticalPaths[MAX_N+1];
bool visited[MAX_N+1];

int max2(int a, int b){ return a>b?a:b; }

// getTime(idx) : idx번 도시까지 모든 사람이 도달하기 위해 필요한 최소 시간
int getTime(int idx){
	if(time[idx]>=0) return time[idx];
	if(city[idx].inEdgeList.size()==0) return (time[idx]=0);

	int ret=0;
	for(int i=0; i<city[idx].inEdgeList.size(); i++){
		int precity=city[idx].inEdgeList[i].first;
		int cost=city[idx].inEdgeList[i].second;
		if(reachable[precity]) ret=max2(ret,getTime(precity)+cost); // start에서 시작하여 갈 수 있는 도시만 고려해야 한다.
	}

	return (time[idx]=ret);
}

// getCriticalPaths(idx) : 시작 도시가 start이고 idx번 도시를 종료 도시로 했을 때, critical path의 수
int getCriticalPaths(int idx){
	if(visited[idx]) return 0; // 중복 덧셈 방지 (반드시 필요)
	visited[idx]=true;

	if(criticalPaths[idx]>=0) return criticalPaths[idx];
	if(city[idx].inEdgeList.size()==0) return (criticalPaths[idx]=0);

	int ret=0;
	for(int i=0; i<city[idx].inEdgeList.size(); i++){
		int precity=city[idx].inEdgeList[i].first;
		int cost=city[idx].inEdgeList[i].second;
		if(reachable[precity] && getTime(precity)+cost==getTime(idx)){ // 임계 경로(critical path)의 조건 만족
			ret+=getCriticalPaths(precity)+1;
		}
	}
	return (criticalPaths[idx]=ret);
}

int main(void){
	scanf("%d %d",&N,&M);
	for(int i=0; i<M; i++){
		int from,to,cost;
		scanf("%d %d %d",&from,&to,&cost);
		city[from].outEdgeList.push_back(make_pair(to,cost));
		city[to].inEdgeList.push_back(make_pair(from,cost)); city[to].indegree++;
	}
	scanf("%d %d",&start,&end);

	// reachable 확인
	queue <int> q;
	q.push(start); reachable[start]=true;
	while(!q.empty()){
		int f=q.front(); q.pop();
		for(int i=0; i<city[f].outEdgeList.size(); i++){
			int nextcity=city[f].outEdgeList[i].first;
			if(!reachable[nextcity]){ q.push(nextcity); reachable[nextcity]=true; }
		}
	}

	// time 계산
	for(int i=1; i<=N; i++) time[i]=-1;
	int totalTime=getTime(end);
	printf("%d\n",totalTime);

	// critical path 수 계산
	for(int i=1; i<=N; i++){
		criticalPaths[i]=-1;
		visited[i]=false;
	}	
	int totalCriticalPaths=getCriticalPaths(end);	
	printf("%d\n",totalCriticalPaths);
    
	return 0;
}
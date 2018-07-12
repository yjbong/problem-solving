#include <cstdio>
#include <vector>
#include <utility>
#include <queue>

#define INF 100000000
#define MAX_CITIES 100
#define MAX_BUDGET 10000

using namespace std;

typedef pair<int,pair<int,int> > iii; // first=d array value, second.first=city num, second.second=budget used

typedef struct{
	int dst; // destination city
	int length; // road length
	int fee; // road fee
}ROAD;

int K; // budget limit
int N; // # of cities
int R; // # of roads

int d[MAX_CITIES+1][MAX_BUDGET+1]; // d[i][j] = minimum distance to city i from city 1 with budget j
vector <ROAD> road[MAX_CITIES+1]; // road[i] = road list from i

priority_queue <iii> pq; // minimum heap for running dijkstra

void dijkstra(int startCity, int startBudgetUsed){

	// init d
	for(int i=0; i<=N; i++)
	for(int j=0; j<=K; j++) d[i][j]=INF;
	d[startCity][startBudgetUsed]=0;

	pq.push(make_pair(-d[startCity][startBudgetUsed], make_pair(startCity, startBudgetUsed)));
	while(!pq.empty()){
		iii top=pq.top(); // top = element of pq with minimum d
		pq.pop();
		int topCity=top.second.first;
		int topBudget=top.second.second;
		for(int i=0; i<road[topCity].size(); i++){
			int curCity=road[topCity][i].dst;	
			int curBudget=topBudget+road[topCity][i].fee;
			int curDistance=d[topCity][topBudget]+road[topCity][i].length;
			if(curBudget<=K && d[curCity][curBudget]>curDistance){
				d[curCity][curBudget]=curDistance;
				pq.push(make_pair(-curDistance, make_pair(curCity, curBudget)));
			}
		}
	}
}

int main(void){

	// input
	scanf("%d",&K);
	scanf("%d %d",&N,&R);
	for(int i=0; i<R; i++){
		int s,d,l,t;
		scanf("%d %d %d %d",&s,&d,&l,&t);
		ROAD curRoad;
		curRoad.dst=d, curRoad.length=l, curRoad.fee=t;
		road[s].push_back(curRoad);
	}

	// run dijkstra
	dijkstra(1,0);

	// answer
	int ans=INF;
	for(int i=0; i<=K; i++)
		if(ans>d[N][i]) ans=d[N][i];
	if(ans<INF) printf("%d\n",ans);
	else printf("-1\n");
	
	return 0;
}
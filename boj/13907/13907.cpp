#include <cstdio>
#include <vector>
#include <utility>
#include <queue>

#define INF 1000000000
#define MAX_CITIES 1000

using namespace std;

typedef pair<int,pair<int,int> > iii; // first=d array value, second.first=city num, second.second=# of vertices(except start vertex) in the path

typedef struct{
	int dst; // destination city
	int fee; // road fee
}ROAD;

int N; // # of cities
int M; // # of roads
int K; // # of increasing tax
int S; // source city
int D; // destination city

int d[MAX_CITIES+1][MAX_CITIES+1]; // d[i][j] = minimum distance to city i from city 1 with j vertices(except start vertex) in the path
vector <ROAD> road[MAX_CITIES+1]; // road[i] = road list from i

priority_queue <iii> pq; // minimum heap for running dijkstra

void dijkstra(int startCity, int pathLen){

	// init d
	for(int i=0; i<=N; i++)
	for(int j=0; j<=N; j++) d[i][j]=INF;
	d[startCity][0]=0;

	pq.push(make_pair(-d[startCity][0], make_pair(startCity, 0)));
	while(!pq.empty()){
		iii top=pq.top(); // top = element of pq with minimum d
		pq.pop();
		int topCity=top.second.first;
		int topPathLen=top.second.second;
		for(int i=0; i<road[topCity].size(); i++){
			int curCity=road[topCity][i].dst;
			int curPathLen=topPathLen+1;
			int curCost=d[topCity][topPathLen]+road[topCity][i].fee;
			if(curPathLen<=N && d[curCity][curPathLen]>curCost){
				d[curCity][curPathLen]=curCost;
				pq.push(make_pair(-curCost, make_pair(curCity, curPathLen)));
			}
		}
	}
}

int main(void){

	// input
	scanf("%d %d %d",&N,&M,&K);
	scanf("%d %d",&S,&D);
	for(int i=0; i<M; i++){
		int a,b,w;
		scanf("%d %d %d",&a,&b,&w);
		ROAD curRoad;
		curRoad.dst=b, curRoad.fee=w;
		road[a].push_back(curRoad);
		curRoad.dst=a, curRoad.fee=w;
		road[b].push_back(curRoad);
	}

	// run dijkstra
	dijkstra(S,0);

	int ans=INF;
	for(int j=0; j<=N; j++)
		if(ans>d[D][j]) ans=d[D][j];
	printf("%d\n",ans);

	int totalP=0;
	for(int i=0; i<K; i++){
		int curP; // current increasing tax amount
		scanf("%d",&curP);
		totalP+=curP;

		ans=INF;
		for(int j=0; j<=N; j++)
			if(ans>d[D][j]+j*totalP) ans=d[D][j]+j*totalP;
		printf("%d\n",ans);
	}

	return 0;
}
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 10000
#define MAXP 100000
#define INF 1000000000
#define DEBUG 0
using namespace std;
int N; // # of nations
int P; // # of roads
int natCost[MAXN+1]; // natCost[i] = cost for visiting i-th nation
typedef struct{
    int v1; // nation 1
    int v2; // nation 2
    int cost;
    int actualCost;
}ROAD;
ROAD road[MAXP];

bool compare(ROAD a, ROAD b){ return a.actualCost<=b.actualCost; }

int parent[MAXN+1];
int find2(int a){
    while(parent[a]>=0) a=parent[a];
    return a;
}
bool union2(int a, int b){
    int pa=find2(a), pb=find2(b);
    if(pa==pb) return false;
    else if(parent[pa]<parent[pb]) parent[pb]=pa;
    else if(parent[pa]>parent[pb]) parent[pa]=pb;
    else{ parent[pb]=pa; parent[pa]--; }
    return true;
}

int main(void){
    scanf("%d %d",&N,&P);
    int minNatCost = INF;
    for(int i=1; i<=N; i++){
        scanf("%d", &natCost[i]);
        if(minNatCost>natCost[i]) minNatCost=natCost[i];
    }
    for(int i=0; i<P; i++){
        scanf("%d %d %d", &road[i].v1, &road[i].v2, &road[i].cost);
        // 어떤 간선을 선택하면, 그 간선은 2번 지나며 간선으로 연결된 두 도시는 각각 1번씩 더 방문하게 된다.
        road[i].actualCost = road[i].cost*2 + natCost[road[i].v1] + natCost[road[i].v2];
    }
    sort(road, road+P, compare);
#if DEBUG
    for(int i=0; i<P; i++)
        printf("nation %d-> nation %d, cost = %d, actualCost = %d\n", road[i].v1, road[i].v2, road[i].cost, road[i].actualCost);
#endif
    memset(parent, -1, sizeof(int)*MAXN);
    int ans=0;
    int pickRoads=0;
    for(int i=0; i<P && pickRoads<N-1; i++){
        if(union2(road[i].v1, road[i].v2)){
            ans+=road[i].actualCost;
            pickRoads++;
        }
    }
    ans+=minNatCost; // 여기서 출발 도시는 한번 더 방문하게 되므로, 가장 도착 비용이 낮은 도시에서 출발
    printf("%d\n", ans);
    return 0;
}

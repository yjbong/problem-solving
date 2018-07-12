#include <cstdio>
#include <vector>
#include <queue>
#define INF 1000000000
using namespace std;

int n; //  # of towns
int w[11111]; // w[i] = # of people at town i
vector <int> adj[11111]; // adj[i] = adjacent town list of town i
int lv[11111]; // lv[i] = level of town i
queue <int> q;

vector <int> child[11111]; // child[i] = child list of town i


// data structure for topological sort
typedef struct{
	int indeg; // # of in edge
	vector <int> outlist; // list of out edge
}TOP_SORT_V;

TOP_SORT_V tv[11111];
vector <int> sortOrder; // topological sort order

int d[11111][2]; // d[i][0] = maximum score from subtree with town i as root. Not choosing town i
		 // d[i][1] = maximum score from subtree with town i as root. Choosing town i

int max2(int a, int b){ return a>b?a:b; }

int main(void){

	// input
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",&w[i]);
	for(int i=1; i<=n-1; i++){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	// build tree
	lv[1]=0; // assume town 1 is root of tree
	for(int i=2; i<=n; i++) lv[i]=INF;

	q.push(1);
	while(!q.empty()){
		int fv=q.front(); q.pop();
		for(int i=0; i<adj[fv].size(); i++){
			int cv=adj[fv][i];
			if(lv[cv]>lv[fv]+1){
				lv[cv]=lv[fv]+1;
				q.push(cv);
			}
		}
	}

	// build child list and topsort data
	
	// init topsort data
	for(int i=1; i<=n; i++){
		tv[i].indeg=0;
		tv[i].outlist.clear();
	}

	for(int i=1; i<=n; i++){
		for(int j=0; j<adj[i].size(); j++){
			int cv=adj[i][j];
			if(lv[i]<lv[cv]){
				child[i].push_back(cv);
				tv[i].indeg++;
				tv[cv].outlist.push_back(i);
			}
		}
	}
	
	// topological sort
	for(int i=1; i<=n; i++) if(tv[i].indeg==0) q.push(i);
	while(!q.empty()){
		int fv=q.front(); q.pop();
		sortOrder.push_back(fv);
		
		for(int i=0; i<tv[fv].outlist.size(); i++){
			int cv=tv[fv].outlist[i];
			tv[cv].indeg--;
			if(tv[cv].indeg==0) q.push(cv);
		}
	}

	// DP (topological order)
	for(int i=0; i<n; i++){
		int cv=sortOrder[i];
		d[cv][0]=0;
		d[cv][1]=w[cv];

		for(int j=0; j<child[cv].size(); j++){
			if(d[child[cv][j]][0] > d[child[cv][j]][1]){
				d[cv][0] += d[child[cv][j]][0];
			}
			else{
				d[cv][0] += d[child[cv][j]][1];
			}

			d[cv][1] += d[child[cv][j]][0];
		}
	}

	// print max score
	printf("%d\n",max2(d[1][0],d[1][1]));

	return 0;
}
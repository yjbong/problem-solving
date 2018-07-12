#include <cstdio>
#include <queue>
using namespace std;
int n; // # of computers
int e; // # of edges
int a[111][111]; // adjacent mat
bool visited[111];
queue <int> q;

int main(void){
	// input
	scanf("%d %d",&n,&e);
	for(int i=0; i<e; i++){
		int c1,c2;
		scanf("%d %d",&c1,&c2);
		a[c1][c2]=a[c2][c1]=1;
	}
	// bfs from 1
	int ans=0;
	q.push(1);
	visited[1]=true;
	while(!q.empty()){
		int f=q.front();
		q.pop();
		for(int i=1; i<=n; i++){
			if(a[f][i] && visited[i]==false){
				q.push(i);
				visited[i]=true;
				ans++;
			}
		}
	}
	// output
	printf("%d\n",ans);	
	return 0;
}
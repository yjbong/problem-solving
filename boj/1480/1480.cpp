#include <cstdio>
#include <queue>
#include <utility>
#define MAX_JEWELS 13
#define MAX_BAGS 10
#define MAX_CAP 20

using namespace std;
typedef pair<int,int> ii;

int n; // # of jewels
int m; // # of bags
int c; // capacity of each bag
int w[MAX_JEWELS]; // w[i] : weight of i-th jewel
int wsum[1<<MAX_JEWELS]; // wsum[i] = sum of weight of picking state i
bool d[MAX_BAGS+1][1<<MAX_JEWELS]; // d[i][j] = true if picking state j is possible with i bags

queue <ii> q;

int main(void){

	// input
	scanf("%d %d %d",&n,&m,&c);
	for(int i=0; i<n; i++) scanf("%d",&w[i]);
	
	// calc wsum
	for(int i=0; i<(1<<n); i++){
		wsum[i]=0;
		for(int j=0; j<n; j++) if(i&(1<<j)) wsum[i]+=w[j];
	}

	// calc d
	q.push(make_pair(0,0));
	d[0][0]=true;
	while(!q.empty()){
		ii f=q.front(); q.pop();
		int fbags=f.first, fstatus=f.second;
		for(int i=0; i<(1<<n); i++){
			if(!(fstatus&i) && wsum[i]<=c){ // possible to put new jewel set i
				int cbags=fbags+1;
				int cstatus=fstatus|i;
				if(cbags<=m && !d[cbags][cstatus]){
					q.push(make_pair(cbags,cstatus));
					d[cbags][cstatus]=true;
				}
			}
		}
	}

	// calc answer
	int ans=0;
	for(int i=0; i<=m; i++)
	for(int j=0; j<(1<<n); j++){
		if(d[i][j]){
			int curAns=0;
			for(int k=0; k<n; k++) if(j&(1<<k)) curAns++;
			if(ans<curAns) ans=curAns;
		}
	}
	printf("%d\n",ans);
	return 0;
}
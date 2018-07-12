#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#define INF 1000000000
using namespace std;
typedef pair<int,int> ii;

bool compFunc(ii i, ii j){
	if(i.first!=j.first) return (i.first<j.first);
	else return (abs(i.second)<abs(j.second));
}

int n;
vector <ii> b; // b[i].first = x-coord of i-th building, b[i].second = y-coord of i-th building
int d[10001]; // d[i] = min cost to cover b[0~i]
int c[10001]; // at the iteration in order to calc d[i], c[j] = cost to cover b[j~i]

int max2(int a, int b){ return a>b?a:b; };
int min2(int a, int b){ return a<b?a:b; };

int main(void){

	scanf("%d",&n);
	for(int i=0; i<n; i++){
		int x,y;
		scanf("%d %d",&x,&y);
		b.push_back(make_pair(x,y));
	}

	// sort increasingly by x-coord
	sort(b.begin(), b.end(), compFunc);


	// run DP

	// init array c for 0-th iteration
	c[0]=abs(b[0].second)*2;
	for(int i=1; i<n; i++) c[i]=0;

	d[0]=abs(b[0].second)*2;
	for(int i=1; i<n; i++){
		d[i]=INF;

		// update array c for i-th iteration
		for(int j=0; j<=i; j++){
			if(j==i) c[j]=abs(b[j].second)*2;
			else c[j]=max2(c[j], max2(b[i].first-b[j].first, abs(b[i].second)*2));
		}

		for(int j=0; j<=i; j++){ // cover build[j~i] with one square
			int curCost = c[j];
			if(j>0) curCost += d[j-1];

			d[i]=min2(d[i],curCost);
		}
	}
	printf("%d\n",d[n-1]);
	return 0;
}
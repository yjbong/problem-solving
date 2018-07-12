#include <cstdio>
#include <vector>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
int n; // # of points
ll nx[100001]; // x[i] = # of points with x coord = i
ll ny[100001]; // y[i] = # of points with y coord = i

vector<ii> p; // point list

int main(void){

	// input
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		int x,y;
		scanf("%d %d",&x,&y);
		nx[x]++; ny[y]++;
		p.push_back(make_pair(x,y));
	}
	// answer
	ll ans=0;
	for(int i=0; i<n; i++){
		int cx=p[i].first, cy=p[i].second;
		ans += (nx[cx]-1)*(ny[cy]-1);
	}
	printf("%lld\n",ans);

	return 0;
}
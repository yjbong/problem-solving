#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;

int n; // # of gas stations
ii station[10000]; // first  : distance between gas station and starting position
		   // second : recharging amount of fuel
int l; // distance between starting position and town
int p; // current amount of fuel

priority_queue <int> pq; // max heap

int main(void){

	// input
	scanf("%d",&n);
	for(int i=0; i<n; i++)
		scanf("%d %d",&(station[i].first),&(station[i].second));
	sort(station,station+n);
	scanf("%d %d",&l,&p);

	// greedy method using max heap
	int stops=0; // minimum number of stops required
	int start=0;

	bool ok=true;
	while(p<l){
		for(int i=start; i<n; i++){
			if(p>=station[i].first){
				pq.push(station[i].second);
				start=i+1;
			}
			else break;
		}

		// stop at possible gas station with largest amount
		if(!pq.empty()){
			p+=pq.top();
			pq.pop();
			stops++;
		}
		// no more gas stations available
		else{
			ok=false;
			break;
		}
	}

	// print answer
	if(ok) printf("%d\n",stops);
	else printf("-1\n");
	return 0;
}
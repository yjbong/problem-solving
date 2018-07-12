#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;

int n,k;
priority_queue <ll> pq;
vector <pair<ll,ll> > item;
vector <ll> bag;

int main(void){

	scanf("%d %d",&n,&k);

	for(int i=0; i<n; i++){
		ll m,v;
		scanf("%lld %lld",&m,&v);
		item.push_back(make_pair(m,v));
	}
	for(int i=0; i<k; i++){
		ll c;
		scanf("%lld",&c);
		bag.push_back(c);
	}
	sort(item.begin(), item.end()); // sorting item --> increasing weight
	sort(bag.begin(), bag.end()); // sorting bag --> increasing capacity

	ll ans=0;
	int curItem=0;
	for(int i=0; i<bag.size(); i++){
		while(curItem < item.size()){
			ll curItemWeight = item[curItem].first;
			ll curItemValue = item[curItem].second;
			if(curItemWeight<=bag[i]){
				pq.push(curItemValue);
				curItem++;
			}
			else break;
		}
		if(!pq.empty()){
			ans += pq.top();
			pq.pop();
		}
	}
	printf("%lld\n",ans);
	return 0;
}
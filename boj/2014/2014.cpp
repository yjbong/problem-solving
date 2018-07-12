#include <cstdio>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;
typedef long long ll;

ll k,n;
ll h[100001]; // h[i] = i번째 humble number
ll p[100]; // p : 주어진 소수들

priority_queue <ll> q; // min heap
set <ll> s;

int main(void){
	scanf("%lld %lld",&k,&n);
	for(int i=0; i<k; i++) scanf("%lld",&p[i]);
	sort(p,p+k);

	ll maxVal=0;
	for(int i=0; i<=n; i++){
		if(i==0) h[i]=1;
		else{
			h[i]=-q.top();
			while(!q.empty() && (-q.top()==h[i])) q.pop();
		}
		for(int j=0; j<k; j++){
			ll curVal=h[i]*p[j];
			if(!(q.size()>=n-i && maxVal<curVal)) // pq에 들어있는 값의 개수가 앞으로 구할 humble number의 개수 이상이고, 현재 넣으려는 값이 pq내에 들어있는 최대값보다 클 때, 현재 값은 pq에 넣을 필요가 없음
			if(s.find(-curVal)==s.end()){ // pq에 이미 들어있는 값이라면 넣지 않음
				if(maxVal<curVal) maxVal=curVal;
				q.push(-h[i]*p[j]);
				s.insert(-h[i]*p[j]);
			}
		}
	}

	printf("%lld\n", h[n]);
	return 0;
}
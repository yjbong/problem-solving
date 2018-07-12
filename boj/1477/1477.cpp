#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> rest;
int N; // # of resting places initially built
int M; // # of resting places to be built
int L; // length of highway

// return # of additional rest needed in order to make maximum gap between resting places given number(dist)
int needRestNum(int dist){
	int ans=0;
	for(int i=0; i<rest.size()-1; i++){
		int curLen=rest[i+1]-rest[i];
		ans+=curLen/dist+(curLen%dist>0?1:0)-1;
	}
	return ans;
}

int main(void){

	// input
	scanf("%d %d %d",&N,&M,&L);
	rest.push_back(0);
	rest.push_back(L);
	for(int i=0; i<N; i++){
		int a;
		scanf("%d",&a);
		rest.push_back(a);
	}
	sort(rest.begin(), rest.end());

	// set initial answer (without new resting place)
	int ans=0;
	for(int i=0; i<rest.size()-1; i++){
		int curLen=rest[i+1]-rest[i];
		if(ans<curLen) ans=curLen;
	}

	// update answer
	int left=1, right=ans;
	while(left<=right){
		int mid=(left+right)/2;
		if(needRestNum(mid)<=M){
			if(ans>mid) ans=mid;
			right=mid-1;
		}
		else left=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}
#include <cstdio>
#include <algorithm>
#include <utility>
#include <map>

using namespace std;
typedef pair<int,int> ii;

int n; // # of lines
ii l[100000]; // l[i].first = connect pos at pole A of line i, l[i].second = pos at pole B of line i
int d[100000]; // d[i] = length of LIS which ends at l[i].second
int t[100000]; // t[i] = j if d[i]'s value made from d[j]. (So, d[i]=d[j]+1), -1 if N/A

int BIT[1<<20];
const int base = 1<<19;

map <int,int> BtoA; // convert B's pos to A's pos
map <int,int> AtoD; // convert A's pos to array d's idx

bool check[500001];

int max2(int a, int b) { return a>b?a:b; }
void updateBIT(int idx, int item){
	idx += base;
	if(BIT[idx]<item){
		BIT[idx]=item;
		idx/=2;
		while(idx>=1){
			BIT[idx]=max2(BIT[idx*2], BIT[idx*2+1]);
			idx/=2;
		}
	}
}

int getMaxIdx(int left, int right){

	int maxVal=0;
	int maxIdx=-1;

	left += base;
	right += base;

	// find index of node which has max value
	while(left<right){
		if(left%2==0) left/=2;
		else{
			if(maxVal<BIT[left]){
				maxVal=BIT[left];
				maxIdx=left;
			}
			left=(left+1)/2;
		}
		if(right%2==1) right/=2;
		else{
			if(maxVal<BIT[right]){
				maxVal=BIT[right];
				maxIdx=right;
			}
			right=(right-1)/2;
		}
	}
	
	if(left==right){
		if(maxVal<BIT[left]){
			maxVal=BIT[left];
			maxIdx=left;
		}
	}

	// find index of LEAF node which has max value
	if(maxIdx>=0){
		while(maxIdx<base){
			if(BIT[maxIdx*2]>BIT[maxIdx*2+1]) maxIdx=maxIdx*2;
			else maxIdx=maxIdx*2+1;
		}
		return (maxIdx-base);
	}
	else return -1;
}

int main(void){

	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%d %d",&l[i].first, &l[i].second);
	sort(l,l+n);
	
	for(int i=0; i<n; i++){
		check[l[i].first]=true;
		BtoA[l[i].second]=l[i].first;
		AtoD[l[i].first]=i;
	}

	// run DP
	for(int i=0; i<n; i++){
		int curMaxIdx=getMaxIdx(0,l[i].second);
		//printf("for d[%d], search range is 0~%d\n", i,l[i].second);
		//printf("curMaxIdx from BIT is %d\n", curMaxIdx);
	
		if(curMaxIdx>=0){
			t[i]=AtoD.find((BtoA.find(curMaxIdx))->second)->second;
			d[i]=d[t[i]]+1;
			//printf("d[%d]=d[%d]+1=%d\n", i, t[i], d[i]);
		}

		else{
			//printf("d[%d]=1\n", i);
			d[i]=1; t[i]=-1;
		}

		updateBIT(l[i].second, d[i]);
	}

	int ans=0;
	int ansIdx=0;
	for(int i=0; i<n; i++){
		if(ans<d[i]){
			ans=d[i];
			ansIdx=i;
		}
	}

	// print answer
	printf("%d\n",n-ans);
	//for(int i=0; i<n; i++) printf("t[%d]=%d\n", i,t[i]);
	while(ansIdx>=0){
		//printf("ansidx=%d, A=%d\n",ansIdx, l[ansIdx].first);
		check[l[ansIdx].first]=false;
		ansIdx=t[ansIdx];
	}
	for(int i=0; i<=500000; i++) if(check[i]) printf("%d\n",i);
	return 0;
}
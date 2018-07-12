#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
bool isNotPrime[2001]; // isNotPrime[i] = false if number i is prime
int a[50]; // if first num is even, a[i] = i-th even number, otherwise a[i] = i-th odd number
int as; // size of a
int b[50]; // if first num is even, b[i] = i-th odd number, otherwise b[i] = i-th even number
int bs; // size of b

int firstMatchIdx; // firstMatchIdx = x, if a[0](firstNum) and b[x] are matched now

int match[50]; // match[j] = i, if b[j] is matched with a[j] (negative if b[j] is not matched)
bool visit[50];

vector <int> ans; // answer list

// if a[idx] is possible to match with any b[x], return true
bool matched(int idx){
	if(visit[idx]) return false;
	visit[idx]=true;
	for(int i=0; i<bs; i++){
		if(i!=firstMatchIdx && !isNotPrime[a[idx]+b[i]]){ // matching (a[0],b[firstMatchIdx]) should be remained
			if((match[i]==-1) || ((match[i]!=idx) && matched(match[i]))){
				match[i]=idx;
				return true;
			}
		}
	}
	return false;
}

int main(void){

	// calc isNotPrime
	isNotPrime[0]=isNotPrime[1]=true;
	for(int i=2; i<=2000; i++)
		if(!isNotPrime[i])
			for(int j=i*2; j<=2000; j+=i) isNotPrime[j]=true;

	// process input
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		bool firstEven;
		int num;
		scanf("%d",&num);
		if(i==0) firstEven = (num%2==0) ? true : false;
		
		if((firstEven && num%2==0) || (!firstEven && num%2==1)) a[as++]=num;
		else b[bs++]=num;
	}

	if(as==bs){
		for(int i=0; i<bs; i++){
			if(!isNotPrime[a[0]+b[i]]){
				// init match
				for(int j=0; j<bs; j++) match[j]=-1;
				// a[0] and b[i] is matched
				match[i]=0; firstMatchIdx=i;
		
				bool ok=true;
				// check if other numbers are fully matched
				for(int j=1; j<as; j++){

					// init visit
					for(int k=0; k<as; k++) visit[k]=false;

					if(!matched(j)){
						ok=false;
						break;
					}
				}
				// add b[i] if fully matched
				if(ok) ans.push_back(b[i]);
			}
		}
	}

	// print answer
	if(ans.size()>0){
		sort(ans.begin(), ans.end());
		for(int i=0; i<ans.size(); i++) printf("%d ",ans[i]);
		printf("\n");
	}
	else printf("-1\n");

	return 0;
}
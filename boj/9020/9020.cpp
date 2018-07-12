#include <cstdio>
#include <cstdlib>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int,int> ii;
int t; // # of test cases
bool p[10001];
vector <int> prime; // prime num list
int main(void){

	// make prime num list
	p[0]=p[1]=true;
	for(int i=2; i<=10000; i++){
		if(!p[i]){
			prime.push_back(i);
			for(int j=i*2; j<=10000; j+=i) p[j]=true;
		}
	}

	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		ii ans=make_pair(0,1000000);
		for(int i=0; i<prime.size(); i++){
			int left=0, right=prime.size()-1;
			while(left<=right){ // binary search
				int mid=(left+right)/2;
				if(prime[mid]<(n-prime[i])) left=mid+1;
				else if(prime[mid]>(n-prime[i])) right=mid-1;
				else{
					if(abs(ans.first-ans.second) > abs(prime[i]-prime[mid])){ // update answer
						if(prime[i]<prime[mid]){ ans.first=prime[i]; ans.second=prime[mid]; }
						else{ ans.first=prime[mid]; ans.second=prime[i]; }
					}
					break;
				}
			}
		}
		printf("%d %d\n",ans.first,ans.second);
	}

	return 0;
}
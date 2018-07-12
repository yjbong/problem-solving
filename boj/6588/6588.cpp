#include <cstdio>
#include <vector>
using namespace std;
bool isNotPrime[1000001];
vector <int> prime;

int main(void){
	isNotPrime[0]=isNotPrime[1]=true;
	for(int i=2; i<=1000000; i++)
		if(!isNotPrime[i])
			for(int j=i*2; j<=1000000; j+=i)
				isNotPrime[j]=true;

	for(int i=0; i<=1000000; i++)
		if(!isNotPrime[i]) prime.push_back(i);
	
	while(1){
		int n;
		scanf("%d",&n);
		if(n==0) break;

		bool pairFound=false;
		int ans;
		for(int i=0; i<prime.size(); i++){
			if(prime[i]%2==0) continue; // 짝수 소수(=2)는 패스
			int left=i, right=prime.size()-1;
			while(left<=right){
				int mid=(left+right)/2;
				if(prime[mid]<n-prime[i]) left=mid+1;
				else if(prime[mid]>n-prime[i]) right=mid-1;
				else{
					pairFound=true;
					break;
				}
			}
			if(pairFound){
				ans=prime[i];
				break;
			}
		}
		if(pairFound) printf("%d = %d + %d\n",n,ans,n-ans);
		else printf("Goldbach's conjecture is wrong.\n");
	}
	
	return 0;
}
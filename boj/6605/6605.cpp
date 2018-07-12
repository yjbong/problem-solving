#include <cstdio>
#include <set>
using namespace std;
long long h[5842+1]; // h[i] = i-th humble number
set<long long> mySet;
const int factor[4]={2,3,5,7};

int main(void){

	for(int i=1; i<=5842; i++){
		if(i==1) h[i]=1;
		else h[i]=*(mySet.upper_bound(h[i-1]));
		for(int j=0; j<4; j++) mySet.insert(h[i]*factor[j]);
	}
	while(1){
		int n;
		scanf("%d",&n);
		if(n==0) break;
		if(n%100>=10 && n%100<=19) printf("The %dth humble number is %lld.\n", n, h[n]);
		else if(n%10==1) printf("The %dst humble number is %lld.\n", n, h[n]);
		else if(n%10==2) printf("The %dnd humble number is %lld.\n", n, h[n]);
		else if(n%10==3) printf("The %drd humble number is %lld.\n", n, h[n]);
		else printf("The %dth humble number is %lld.\n", n, h[n]);
	}
	return 0;
}
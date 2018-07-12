#include <cstdio>
#include <algorithm>
using namespace std;
int n;
long long a[500000];
long long sorted_a[500000]; // sorted increasingly

int main(void){

	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%lld",&a[i]);
	for(int i=0; i<n; i++) sorted_a[i]=a[i];
	sort(sorted_a,sorted_a+n);

	int ans=0;
	for(int i=0; i<n; i++){

		// binary search on sorted_a
		int left=0, right=n-1;
		int idx=0;
		while(left<=right){
			int mid=(left+right)/2;
			if(sorted_a[mid]<a[i]) left=mid+1;
			else if(sorted_a[mid]>a[i]) right=mid-1;
			else{
				if(idx<mid) idx=mid;
				left=mid+1;
			}
		}
		if(ans<i-idx+1) ans=i-idx+1;
	}
	printf("%d\n",ans);
	return 0;
}
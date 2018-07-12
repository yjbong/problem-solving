#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
int n;
ll a[500000];
int freq[8001];

ll avg;
ll mean;
ll common;
ll range;
bool first;

int main(void){

	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%lld",&a[i]);
	sort(a,a+n);

	mean=a[(n-1)/2];
	range=a[n-1]-a[0];

	avg=0;
	for(int i=0; i<n; i++){
		avg+=a[i];
		freq[a[i]+4000]++;
	}
	avg = floor((double)(avg)/n + 0.5);

	first=true;
	common = -4000;
	for(int i=-3999; i<=4000; i++){
		if(freq[common+4000] < freq[i+4000]){
			common=i;
			first=true;
		}
		else if(freq[common+4000] == freq[i+4000]){
			if(first){
				common=i;
				first=false;
			}
		}
	}
	printf("%lld\n",avg);
	printf("%lld\n",mean);
	printf("%lld\n",common);
	printf("%lld\n",range);
	return 0;
}
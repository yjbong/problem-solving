#include <cstdio>
#include <algorithm>
using namespace std;
int a[100000];
int main(void){
	int n,i,j;
	scanf("%d",&n);
	for(i=0; i<n; i++) scanf("%d",&a[i]);
	sort(a,a+n);
	int sol=0;
	for(i=n-1,j=1; i>=0; i--,j++) if(sol<a[i]*j) sol=a[i]*j;	
	printf("%d\n",sol);
	return 0;
}
#include <cstdio>
#include <algorithm>
using namespace std;

int a[55];
int main(void){

	int l,n;
	
	scanf("%d",&l);
	for(int i=0; i<l; i++) scanf("%d",&a[i]);
	scanf("%d",&n);
	sort(a,a+l);

	int lb=1, ub=a[l-1]-1;
	
	for(int i=0; i<l; i++){
		if(a[i]<n) lb=a[i]+1;
		else{
			if(a[i]==n) lb=a[i]+1;
			ub=a[i]-1;
			break;
		}
	}
	int sol=0;
	for(int i=lb; i<=ub; i++)
		for(int j=i+1; j<=ub; j++)
			if(i<=n && n<=j) sol++;
	
	printf("%d\n",sol);
	return 0;
}
#include <cstdio>
int a[100];
int main(void){
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0; i<n; i++) scanf("%d",&a[i]);

	int curSum=0;
	for(int i=0; i<k; i++) curSum+=a[i];

	int ans=curSum;
	for(int i=k; i<n; i++){
		curSum+=(a[i]-a[i-k]);
		if(ans<curSum) ans=curSum;
	}
	printf("%d\n",ans);
	
	return 0;
}
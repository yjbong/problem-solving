#include <cstdio>
int main(void){
	int n,k;
	scanf("%d %d",&n,&k);
	int c=0;
	int ans=0;
	for(int i=1; i<=n; i++){
		if(n%i==0){
			c++;
			if(c==k){ ans=i; break; }
		}
	}
	printf("%d\n",ans);
	return 0;
}
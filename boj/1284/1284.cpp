#include <cstdio>
int main(void){
	while(1){
		int n;
		scanf("%d",&n);
		if(n==0) break;

		int ans=1;
		while(n>0){
			if(n%10==1) ans+=2;
			else if(n%10==0) ans+=4;
			else ans+=3;
			ans++;
			n/=10;
		}
		printf("%d\n",ans);
	}
	return 0;
}
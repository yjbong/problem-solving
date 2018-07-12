#include <cstdio>
bool dgt[10];
int main(void){

	int t;
	scanf("%d",&t);
	while(t--){
		for(int i=0; i<=9; i++) dgt[i]=false;
		int x;
		scanf("%d",&x);
		while(x>0){
			dgt[x%10]=true;
			x/=10;
		}

		int ans=0;
		for(int i=0; i<=9; i++) if(dgt[i]) ans++;
		printf("%d\n",ans);
	}
	return 0;
}
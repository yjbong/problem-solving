#include <cstdio>
int main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		int s,n;
		scanf("%d %d",&s,&n);
		for(int i=0; i<n; i++){
			int q,p;
			scanf("%d %d",&q,&p);
			s+=q*p;
		}
		printf("%d\n",s);
	}
	return 0;
}
#include <cstdio>
int main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int sum=0;
		for(int i=0; i<n; i++){
			int num;
			scanf("%d",&num);
			sum+=num;
		}
		printf("%d\n",sum);
	}
	return 0;
}
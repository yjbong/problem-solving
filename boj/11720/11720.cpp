#include <cstdio>
int N;
int main(void){
	scanf("%d",&N);
	int ans=0;
	for(int i=0; i<N; i++){
		int num;
		scanf("%1d",&num);
		ans+=num;
	}
	printf("%d\n",ans);
	return 0;
}
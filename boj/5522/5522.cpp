#include <cstdio>
int main(void){
	int ans=0,tmp;
	for(int i=0; i<5; i++){
		scanf("%d",&tmp);
		ans+=tmp;
	}
	printf("%d\n",ans);
	return 0;
}
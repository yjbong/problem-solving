#include <cstdio>
int main(void){
	int ans=0, cur=0;
	for(int i=0; i<10; i++){
		int in,out;
		scanf("%d %d",&out,&in);
		cur+=in-out;
		if(ans<cur) ans=cur;
	}
	printf("%d\n",ans);
	return 0;
}
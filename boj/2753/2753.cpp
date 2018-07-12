#include <cstdio>
int main(void){
	int y,ans;
	scanf("%d",&y);
	if(y%400==0) ans=1;
	else if(y%100==0) ans=0;
	else if(y%4==0) ans=1;
	else ans=0;
	printf("%d\n",ans);		
	return 0;
}
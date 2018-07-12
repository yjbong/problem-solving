#include <cstdio>
int main(void){
	int a[5];
	for(int i=0; i<5; i++) scanf("%d",&a[i]);
	int ans=0;
	for(int i=0; i<5; i++) ans+=a[i]*a[i];
	ans%=10;
	printf("%d\n",ans);
	return 0;
}
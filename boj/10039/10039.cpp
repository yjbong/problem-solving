#include <cstdio>
int main(void){
	int a[5];
	for(int i=0; i<5; i++) scanf("%d",&a[i]);

	int ans=0;
	for(int i=0; i<5; i++) ans+=(a[i]<40?40:a[i]);
	ans/=5;
	printf("%d\n",ans);
	return 0;
}
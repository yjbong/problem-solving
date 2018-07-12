#include <cstdio>
#include <algorithm>
int a[10];
int main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		for(int i=0; i<10; i++) scanf("%d",&a[i]);
		std::sort(a,a+10);
		printf("%d\n",a[7]);
	}	
	return 0;
}
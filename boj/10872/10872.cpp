#include <cstdio>
int facto[13];
int main(void){
	facto[0]=1;
	for(int i=1; i<=12; i++) facto[i]=facto[i-1]*i;
	int n;
	scanf("%d",&n);
	printf("%d\n",facto[n]);
	return 0;
}
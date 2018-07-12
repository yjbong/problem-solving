#include <cstdio>
#include <algorithm>
int a[3];
char s[5];
int main(void){
	for(int i=0; i<3; i++) scanf("%d",&a[i]);
	scanf("\n");
	std::sort(a,a+3);
	scanf("%s",s);
	for(int i=0; i<3; i++)
		printf("%d ",a[s[i]-'A']);
	printf("\n");
	return 0;
}
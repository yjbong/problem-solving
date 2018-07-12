#include <cstdio>
#include <cstring>
char s[55]; // 그릇이 놓인 상태
int n; // 그릇의 수
int main(void){
	scanf("%s",s);
	n=strlen(s);
	int ans=10;
	for(int i=1; i<n; i++) ans+=(s[i]==s[i-1])?5:10;
	printf("%d\n",ans);
	return 0;
}
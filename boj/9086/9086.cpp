#include <cstdio>
#include <cstdlib>
#include <cstring>
int t;
char s[1001];
int main(void){
	scanf("%d\n",&t);
	while(t--){
		gets(s);
		printf("%c%c\n",s[0],s[strlen(s)-1]);
	}
	return 0;
}
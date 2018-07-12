#include <cstdio>
#include <cstring>
char s[111];
int main(void){
	scanf("%s",s);
	int commas=0;
	for(int i=0; i<strlen(s); i++) if(s[i]==',') commas++;
	printf("%d\n",commas+1);
	return 0;
}
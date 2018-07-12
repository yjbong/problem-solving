#include <cstdio>
#include <cstring>
char s[101];
int main(void){
	scanf("%s",s);
	for(int i=0; i<strlen(s); i++)
		if(i==0 || s[i-1]=='-') printf("%c",s[i]);
	printf("\n");	
	return 0;
}
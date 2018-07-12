#include <cstdio>
#include <cstring>
char s[101];
int main(void){
	scanf("%s",s);
	for(int i=0; i<strlen(s); i++){
		if(s[i]>='A' && s[i]<='Z') printf("%c",s[i]-'A'+'a');
		else printf("%c",s[i]-'a'+'A');
	}
	printf("\n");
	return 0;
}
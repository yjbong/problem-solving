#include <cstdio>
#include <cstring>
char s[101];
int main(void){
	scanf("%s",s);
	for(int i=0; i<strlen(s); i++){
		printf("%c",s[i]);
		if(i%10==9) printf("\n");
	}
	return 0;
}
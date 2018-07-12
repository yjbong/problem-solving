#include <cstdio>
#include <cstring>
char s[21];
int main(void){
	int t;
	scanf("%d\n",&t);
	while(t--){
		int r;
		scanf("%d %s",&r,s);
		for(int i=0; i<strlen(s); i++)
			for(int j=0; j<r; j++) printf("%c",s[i]);
		printf("\n");
	}
	return 0;
}
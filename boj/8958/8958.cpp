#include <cstdio>
#include <cstring>
int t;
char s[81];
int main(void){
	scanf("%d",&t);
	while(t--){
		scanf("%s",s);
		int totalScore=0;
		int lastScore=0;
		for(int i=0; i<strlen(s); i++){
			if(s[i]=='O'){
				lastScore++;
				totalScore+=lastScore;
			}
			else lastScore=0;
		}
		printf("%d\n",totalScore);
	}
	return 0;
}
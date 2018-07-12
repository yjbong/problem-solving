#include <cstdio>
#include <cstring>
char text[2501];
char word[51];
int main(void){
	gets(text);
	gets(word);

	int curStart=0;
	int ans=0;
	while(curStart+strlen(word)-1<strlen(text)){
		bool found=true;
		for(int i=0; i<strlen(word); i++)
			if(word[i]!=text[curStart+i]){ found=false; break; }
		if(found){
			ans++;
			curStart+=strlen(word);
		}
		else curStart++;
	}
	printf("%d\n",ans);
	return 0;
}
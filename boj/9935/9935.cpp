#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
char word[1000000+1];
char bomb[36+1];
char ans[1000000+1];
int ansLen;

stack <char> stk;
int main(void){
	gets(word);
	gets(bomb);
	int wordLen=strlen(word);
	int bombLen=strlen(bomb);

	for(int i=0; i<wordLen; i++){
		stk.push(word[i]);
		char curBomb[36+1];
		if(stk.size()>=bombLen){
			stack <char> tmpStk;
			for(int j=0; j<bombLen; j++){
				tmpStk.push(stk.top());
				stk.pop();
			}
			for(int j=0; j<bombLen; j++){
				curBomb[j]=tmpStk.top();
				tmpStk.pop();
			}
			curBomb[bombLen]='\0';

			// 현재 스택에 있는 최근 bombLen 길이의 문자열이 bomb와 일치하지 않는 경우, 문자열 curBomb는 스택에 다시 push된다.
			// (bomb와 일치하는 경우는 폭발한 것이므로 push 하지 않음)
			if(strcmp(curBomb,bomb)){
				for(int j=0; j<bombLen; j++) stk.push(curBomb[j]);
			}
		}
	}
	if(stk.size()==0) printf("FRULA\n");
	else{
		while(!stk.empty()){
			ans[ansLen++]=stk.top();
			stk.pop();
		}
		for(int i=0; i<ansLen/2; i++){
			char tmp=ans[i];
			ans[i]=ans[ansLen-1-i];
			ans[ansLen-1-i]=tmp;
		}
		printf("%s\n",ans);
	}
	return 0;
}
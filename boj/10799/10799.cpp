#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
char str[100001];
int strLen;
char input[100001];
int inputLen;
stack <char> stk;

int main(void){
	scanf("%s",str);
	strLen=strlen(str);
	inputLen=0;
	for(int i=0; i<strLen; i++){
		if(i<strLen-1 && str[i]=='(' && str[i+1]==')'){
			input[inputLen++]='L'; // 레이저
			i++; // 한 글자를 더 건너뜀
		}
		else input[inputLen++]=str[i];
	}

	// 답 계산
	long long ans=0;
	for(int i=0; i<inputLen; i++){
		if(input[i]=='L') ans+=stk.size(); // 레이저인 경우, 현재 스택에 들어있는 막대의 수를 더함
		else if(input[i]=='(') stk.push(input[i]);
		else if(input[i]==')'){ // 막대 1개의 끝
			ans++;
			stk.pop();
		}
	}
	printf("%lld\n",ans);
	return 0;
}
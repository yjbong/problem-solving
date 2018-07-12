#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

char input[11111]; // 중위 표현식 (입력)
stack <char> st;

int main(void){
	scanf("%s", input);
	for (int i = 0; i < strlen(input); i++){
		switch (input[i]){
		case '(':
			// '('는 바로 push하고 끝냄
			st.push(input[i]);
			break;
		case ')':
			// '('를 만날 때까지 pop하면서 출력
			while (!st.empty() && st.top() != '('){
				printf("%c", st.top()); st.pop();
			}
			// '('를 버림
			if(!st.empty()) st.pop();
			break;
		case '*':
		case '/':
			// 자신보다 낮은 우선순위 연산자(+,-)가 나올 때까지 pop하면서 출력
			while (!st.empty() && (st.top() == '*' || st.top() == '/')){
				printf("%c", st.top()); st.pop();
			}
			// 자신을 push
			st.push(input[i]);
			break;
		case '+':
		case '-':
			// +, - 는 최하위 우선순위이므로, 모든 연산자를 pop하면서 출력
			while (!st.empty() && (st.top() == '*' || st.top() == '/' || st.top() == '+' || st.top() == '-')){
				printf("%c", st.top()); st.pop();
			}
			// 자신을 push
			st.push(input[i]);
			break;
		default:
			// 피연산자는 바로 출력
			printf("%c", input[i]);
		}
	}

	// 스택에 남아있는 연산자를 출력
	while (!st.empty()){
		printf("%c", st.top()); st.pop();
	}
	printf("\n");
	return 0;
}
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
stack <int> s;
int main(void){
	int N;
	scanf("%d\n",&N);
	while(N--){
		char cmd[10];
		int num;
		scanf("%s",cmd);
		if(!strcmp(cmd,"push")){
			scanf("%d\n",&num);
			s.push(num);
		}
		else if(!strcmp(cmd,"pop")){
			if(!s.empty()){
				printf("%d\n",s.top());
				s.pop();
			}
			else printf("-1\n");
		}
		else if(!strcmp(cmd,"size")) printf("%d\n",s.size());
		else if(!strcmp(cmd,"empty")){
			if(s.empty()) printf("1\n");
			else printf("0\n");
		}
		else if(!strcmp(cmd,"top")){
			if(!s.empty()){
				printf("%d\n",s.top());
			}
			else printf("-1\n");
		}
	}
	return 0;
}
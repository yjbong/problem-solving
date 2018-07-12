#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
queue <int> q;
int main(void){
	int N;
	scanf("%d\n",&N);
	while(N--){
		char cmd[10];
		int num;
		scanf("%s",cmd);
		if(!strcmp(cmd,"push")){
			scanf("%d\n",&num);
			q.push(num);
		}
		else if(!strcmp(cmd,"pop")){
			if(!q.empty()){
				printf("%d\n",q.front());
				q.pop();
			}
			else printf("-1\n");
		}
		else if(!strcmp(cmd,"size")) printf("%d\n",q.size());
		else if(!strcmp(cmd,"empty")){
			if(q.empty()) printf("1\n");
			else printf("0\n");
		}
		else if(!strcmp(cmd,"front")){
			if(!q.empty()){
				printf("%d\n",q.front());
			}
			else printf("-1\n");
		}
		else if(!strcmp(cmd,"back")){
			if(!q.empty()){
				printf("%d\n",q.back());
			}
			else printf("-1\n");
		}
	}
	return 0;
}
#include <cstdio>
#include <cstring>
int main(void){
	unsigned int s=0; // 집합
	int m; // 연산의 수
	scanf("%d\n",&m);
	while(m--){
		char cmd[10];
		int x;
		scanf("%s",cmd);
		if(strcmp(cmd,"all") && strcmp(cmd,"empty")) scanf("%d",&x); // all,empty 명령이 아닌 경우 x값 읽음

		if(!strcmp(cmd,"add")) s|=(1<<(x-1)); // add 명령
		else if(!strcmp(cmd,"remove")){ if(s&(1<<(x-1))) s-=(1<<(x-1)); } // remove 명령
		else if(!strcmp(cmd,"check")){ s&(1<<(x-1))?printf("1\n"):printf("0\n"); } // check 명령
		else if(!strcmp(cmd,"toggle")){ s&(1<<(x-1))?s-=(1<<(x-1)):s+=(1<<(x-1)); } // toggle 명령
		else if(!strcmp(cmd,"all")){ s=0xfffff; } // all 명령
		else if(!strcmp(cmd,"empty")){ s=0; } // empty 명령
	}	
	return 0;
}
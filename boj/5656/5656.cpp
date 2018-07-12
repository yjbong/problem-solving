#include <cstdio>
#include <cstring>
int main(void){
	int caseNum=1;
	while(1){
		int a,b;
		char op[5];
		scanf("%d %s %d\n",&a,op,&b);
		if(!strcmp(op,"E")) break;

		printf("Case %d: ",caseNum); caseNum++;
		if(!strcmp(op,">")){ a>b ? printf("true\n") : printf("false\n"); }
		else if(!strcmp(op,">=")){ a>=b ? printf("true\n") : printf("false\n"); }
		else if(!strcmp(op,"<")){ a<b ? printf("true\n") : printf("false\n"); }
		else if(!strcmp(op,"<=")){ a<=b ? printf("true\n") : printf("false\n"); }
		else if(!strcmp(op,"==")){ a==b ? printf("true\n") : printf("false\n"); }
		else if(!strcmp(op,"!=")){ a!=b ? printf("true\n") : printf("false\n"); }
	}
	return 0;
}
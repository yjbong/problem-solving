#include <cstdio>
#include <cstring>
char name[22];
int main(void){
	int n;
	scanf("%d",&n);
	while(n--){
		scanf("%s",name);
		for(int i=0; i<strlen(name); i++) if(name[i]>='A' && name[i]<='Z') name[i]+='a'-'A';
		printf("%s\n",name);
	}
	return 0;
}
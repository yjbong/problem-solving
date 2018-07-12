#include <cstdio>
int v;
char s[20];
int main(void){
	scanf("%d %s",&v,s);
	int as=0,bs=0;
	for(int i=0; i<v; i++){
		if(s[i]=='A') as++;
		else if(s[i]=='B') bs++;	
	}
	if(as>bs) printf("A\n");
	else if(as<bs) printf("B\n");
	else printf("Tie\n");
	return 0;
}
#include <cstdio>
#include <cstring>
char str[256];
int main(void){
	while(gets(str)!=NULL){
		if(!strcmp(str,"#")) break;
		int ans=0;
		for(int i=0; i<strlen(str); i++){
			if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u'
			|| str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U') ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
#include <cstdio>
#include <cstring>
char s[1000001];
int zeros,ones;
int main(void){
	scanf("%s",s);
	char old=0;
	for(int i=0; i<strlen(s); i++){
		if(s[i]!=old){
			if(s[i]=='0') zeros++;
			else ones++;
			old=s[i];
		}
	}
	int ans=zeros;
	if(ans>ones) ans=ones;
	printf("%d\n",ans);
	return 0;
}
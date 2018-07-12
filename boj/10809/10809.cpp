#include <cstdio>
#include <cstring>
char s[111];
int a[26];
int main(void){
	for(int i=0; i<26; i++) a[i]=-1;
    scanf("%s",s);
	for(int i=0; i<strlen(s); i++) if(a[s[i]-'a']<0) a[s[i]-'a']=i;
    for(int i=0; i<26; i++) printf("%d ",a[i]);
    printf("\n");
    return 0;
}
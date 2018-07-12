#include <cstdio>
#include <cstring>
char s[111];
int f[26];
int main(void){
    scanf("%s",s);
    for(int i=0; i<strlen(s); i++) f[s[i]-'a']++;
    for(int i=0; i<26; i++) printf("%d ",f[i]);
    printf("\n");
    return 0;
}
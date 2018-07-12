#include <stdio.h>
#include <string.h>
char l[5001];
int f[26];
int main(void){

    int i,max;
    for(i=0; i<26; i++) f[i]=0;
    while(gets(l)!=NULL)
        for(i=0; i<strlen(l); i++) f[l[i]-'a']++;

    max=f[0];
    for(i=1; i<26; i++) if(max<f[i]) max=f[i];
    for(i=0; i<26; i++) if(max==f[i]) printf("%c",i+'a');
    printf("\n");
    return 0;
}
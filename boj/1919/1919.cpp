#include <stdio.h>
#include <string.h>
#define MAXLEN 1000
int abs2(int n){
        return(n<0?(-n):n);
}

char a_occur[26], b_occur[26];
char a[MAXLEN+1], b[MAXLEN+1];
int a_len, b_len;
int main(void){

        int i, sol;
        scanf("%s", a);
        scanf("%s", b);
        a_len=strlen(a);
        b_len=strlen(b);
        for(i=0; i<26; i++) a_occur[i]=b_occur[i]=0;
        for(i=0; i<a_len; i++) a_occur[a[i]-'a']++;
        for(i=0; i<b_len; i++) b_occur[b[i]-'a']++;
        sol=0;
        for(i=0; i<26; i++) sol+=abs2(a_occur[i]-b_occur[i]);
        printf("%d\n", sol);
        return 0;
}
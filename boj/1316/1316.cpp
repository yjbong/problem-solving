#include <cstdio>
#include <cstring>
char s[101];
bool c[26];
int main(void){

    int n,sol=0;
    scanf("%d",&n);
    while(n--){
        scanf("%s",s);
        for(int i=0; i<26; i++) c[i]=false;
        char old='\0';
        bool ok=true;

        for(int i=0; i<strlen(s); i++){
            if(old!=s[i] && c[s[i]-'a']==true) ok=false;
            else{
                old=s[i];
                c[s[i]-'a']=true;
            }
        }
        if(ok) sol++;
    }
    printf("%d\n",sol);
    return 0;
}
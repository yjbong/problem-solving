#include <cstdio>
#include <cstring>
char s[3333];
bool foldable(char *s){
    int len=strlen(s);
    bool ok=true;
    int i,j;
    while(len>1){
        for(i=0, j=len/2+1; i<len/2; i++,j++){
            if(i==(len/2)/2 && s[i]==s[j]){
                ok=false;
                break;
            }
            else if(i!=(len/2)/2 && s[i]!=s[j]){
                ok=false;
                break;
            }
        }
        if(!ok) break;
        len/=2;
    }
    return ok;
}

int main(void){

    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        if(foldable(s)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
#include <cstdio>
#include <cstring>
char s[81];
char now[81][3];
int nows;
int main(void){
    while(1){
        scanf("%s",s);
        if(strcmp(s,"*")==0) break;
        int n=strlen(s);
        bool ok=true;
        for(int i=0; i<=n-2; i++){
            nows=0;
            for(int j=0; j+i+1<n; j++){
                now[nows][0]=s[j], now[nows][1]=s[j+i+1], now[nows][2]='\0';
                nows++;
                for(int k=0; k<nows-1; k++){
                    if(strcmp(now[k],now[nows-1])==0){
                        ok=false;
                        goto out;
                    }
                }
            }
        }
        out:
        if(ok) printf("%s is surprising.\n",s);
        else printf("%s is NOT surprising.\n",s);
    }
    return 0;
}
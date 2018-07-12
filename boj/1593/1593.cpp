#include <cstdio>

char g[3333];
char s[3333333];
int ord[128];
int glen,slen;
int f[52];
int cf[52];
bool fsame[52];
int fsames;
int sol;

int main(void){

    for(int i='A'; i<='Z'; i++) ord[i]=i-'A';
    for(int i='a'; i<='z'; i++) ord[i]=i-'a'+26;

    scanf("%d %d",&glen,&slen);
    scanf("%s",g);
    scanf("%s",s);
    for(int i=0; i<glen; i++) f[ord[g[i]]]++;
    for(int i=0; i<glen; i++) cf[ord[s[i]]]++;
    fsames=0;
    for(int i=0; i<52; i++){
        if(f[i]==cf[i]){
            fsame[i]=true;
            fsames++;
        }
        else fsame[i]=false;
    }
    if(fsames==52) sol=1;
    else sol=0;

    for(int i=1; i+glen<=slen; i++){
        if(s[i-1]!=s[i+glen-1]){
            cf[ord[s[i-1]]]--; cf[ord[s[i+glen-1]]]++;
            if(fsame[ord[s[i-1]]] && f[ord[s[i-1]]]!=cf[ord[s[i-1]]]){
                fsame[ord[s[i-1]]]=false;
                fsames--;
            }
            else if(!fsame[ord[s[i-1]]] && f[ord[s[i-1]]]==cf[ord[s[i-1]]]){
                fsame[ord[s[i-1]]]=true;
                fsames++;
            }
            if(fsame[ord[s[i+glen-1]]] && f[ord[s[i+glen-1]]]!=cf[ord[s[i+glen-1                                                                                                                                                             ]]]){
                fsame[ord[s[i+glen-1]]]=false;
                fsames--;
            }
            else if(!fsame[ord[s[i+glen-1]]] && f[ord[s[i+glen-1]]]==cf[ord[s[i+                                                                                                                                                             glen-1]]]){
                fsame[ord[s[i+glen-1]]]=true;
                fsames++;
            }
        }
        if(fsames==52) sol++;
    }
    printf("%d\n",sol);
    return 0;
}
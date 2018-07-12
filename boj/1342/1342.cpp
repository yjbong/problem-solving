#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[11];
int main(void){

    int l;
    scanf("%s",s);
    l=strlen(s);
    sort(s,s+l);
    int sol=0;
    do{
        bool ok=true;
        char c=s[0];
        for(int i=1; i<l; i++){
            if(c==s[i]){
                ok=false;
                break;
            }
            else c=s[i];
        }
        if(ok) sol++;
    }while(next_permutation(s,s+l));
    printf("%d\n",sol);
    return 0;
}
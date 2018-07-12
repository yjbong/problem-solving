#include <cstdio>
#include <cstring>
char s[1001];
int main(void){
    scanf("%s",s);
    int sl=strlen(s);
    int sol=1000000000;
    for(int i=0; i<sl; i++){
        bool pal=true;
        for(int j=i; j<=i+(sl-1-i)/2; j++){
            if(s[j]!=s[sl-1-(j-i)]){
                pal=false;
                break;
            }
        }
        if(pal && sol>sl+i) sol=sl+i;
    }
    printf("%d\n",sol);
    return 0;
}
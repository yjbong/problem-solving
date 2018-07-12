#include <cstdio>
#include <cstring>
char s[1001];
int main(void){
    scanf("%s",s);
    int l=strlen(s);
    int as=0;
    for(int i=0; i<l; i++) if(s[i]=='a') as++;
    int m=10000;
    for(int i=0; i<l; i++){
        int c=0;
        for(int j=0,k=i; j<as; j++,k=(k+1)%l) if(s[k]!='a') c++;
        if(m>c) m=c;
    }
    printf("%d\n",m);
    return 0;
}
#include<cstdio>
#include<cstring>
char s[101];
char a[1000001];
int p[256];
int main(void){
    gets(s);
    int ss=strlen(s);
    for(int i=0; i<ss; i++) p[s[i]]=i+1;
    gets(a);
    int as=strlen(a);
    int sol=0;
    for(int i=0; i<as; i++)
        sol=(sol*ss+p[a[i]])%900528;
    printf("%d\n",sol);
    return 0;
}
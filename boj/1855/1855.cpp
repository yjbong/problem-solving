#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[222];
char sol[222];
int main(void){

    int k;
    scanf("%d",&k);
    scanf("%s",s);
    int l=strlen(s);

    for(int i=k; i<l; i+=k*2) reverse(s+i, s+i+k);
    int sols=0;
    for(int i=0; i<k; i++)
        for(int j=i; j<l; j+=k) sol[sols++]=s[j];

    sol[sols]='\0';
    printf("%s\n",sol);
    return 0;
}
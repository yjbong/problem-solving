#include <cstdio>
#include <algorithm>
using namespace std;
char s[10];
int t[5];
int a[3];
int main(void){

    scanf("%s",s);
    t[0]=(s[0]-'0')*10+(s[1]-'0');
    t[1]=(s[3]-'0')*10+(s[4]-'0');
    t[2]=(s[6]-'0')*10+(s[7]-'0');
    for(int i=0; i<3; i++) a[i]=i;

    int sol=0;
    do{
        if(t[a[0]]>=1 && t[a[0]]<=12 && t[a[1]]>=0 && t[a[1]]<=59 && t[a[2]]>=0 && t[a[2]]<=59)
            sol++;
    }while(next_permutation(a,a+3));
    printf("%d\n",sol);
    return 0;
}
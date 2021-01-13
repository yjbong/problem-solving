#include <cstdio>
#include <cstring>
#define MAXN 1000
char S[MAXN+1];
char num0[MAXN+5]; // 원래 이진수
char num1[MAXN+5]; // 원래 이진수를 16배
char ans[MAXN+5];
 
int main() {
    scanf("%s",S);
    int L=strlen(S);
    for(int i=0; i<L; i++){
        num0[L-1-i]=S[i]-'0';
        num1[L-1-i+4]=S[i]-'0';
    }
 
    // ans=num0+num1
    int carry=0;
    for(int i=0; i<=L+5; i++){
        ans[i]=num0[i]+num1[i]+carry;
        if(ans[i]>=2){ ans[i]-=2; carry=1; }
        else carry=0;
    }
 
    bool nonzero=false;
    for(int i=L+5; i>=0; i--){
        if(!nonzero && ans[i]==0) continue;
        nonzero=true; printf("%d",ans[i]);
    }
    return 0;
}
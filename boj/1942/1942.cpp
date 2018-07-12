#include <cstdio>
char s[10];
char e[10];
int main(void){

    int t=3;
    while(t--){
        scanf("%s %s",s,e);

        int sh=(s[0]-'0')*10+s[1]-'0';
        int sm=(s[3]-'0')*10+s[4]-'0';
        int ss=(s[6]-'0')*10+s[7]-'0';
        int st=sh*3600 + sm*60 + ss;

        int eh=(e[0]-'0')*10+e[1]-'0';
        int em=(e[3]-'0')*10+e[4]-'0';
        int es=(e[6]-'0')*10+e[7]-'0';
        int et=eh*3600 + em*60 + es;

        int ct=st;
        int sol=0;
        int out=0;
        while(1){
            int nh=ct/3600;
            int nm=(ct%3600)/60;
            int ns=(ct%3600)%60;
            int n=nh*10000+nm*100+ns;

            if(n%3==0) sol++;
            if(out) break;

            ct=(ct+1)%86400;
            if(ct==et) out=1;
        }
        printf("%d\n",sol);
    }
    return 0;
}
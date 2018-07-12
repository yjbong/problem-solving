#include <cstdio>
#include <cstring>
#define MOD 1000000
typedef long long ll;
char s[5001];
ll fib[5001];
int prt[5001],prts=0;
int main(void){

    scanf("%s",s);
    int l=strlen(s);

    fib[0]=1, fib[1]=1;
    for(int i=2; i<=l; i++) fib[i]=(fib[i-1]+fib[i-2])%MOD;

    int cl=0;
    bool ok=true;
    bool c_cal=true;
    for(int i=0; i<l; i++){
        int c;

        if(c_cal){
            if(i>0) c=(s[i-1]-'0')*10+(s[i]-'0');
            else c=s[0]-'0';
        }
        else c_cal=true;

        if(c%10==0){
            if(c<1 || c>26){
                ok=false;
                break;
            }
            else{
                prt[prts++]=cl-1;
                cl=0;
            }
        }

        else{
            if(c>26){
                prt[prts++]=cl;
                cl=0;

                c=s[i]-'0';
                i--;

                c_cal=false;
            }
            else cl++;
        }
    }
    if(cl>0) prt[prts++]=cl;

    if(!ok) printf("0\n");
    else{
        long long sol=fib[prt[0]];
        for(int i=1; i<prts; i++){
             sol=(sol*fib[prt[i]])%MOD;
        }
        printf("%lld\n",sol);
    }
    return 0;
}
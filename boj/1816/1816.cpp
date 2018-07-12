#include <cstdio>
#define LIM 1000000
int s[LIM+1];
int main(void){

    s[0]=s[1]=1;
    int oldst=1,newst;
    while(1){
        int i;
        for(i=oldst+1; i<=LIM; i++) if(!s[i]){
            newst=i;
            break;
        }
        if(i>LIM) break;
        int t=newst*2;
        while(t<=LIM) s[t]=1, t+=newst;
        oldst=newst;
    }
    int t;
    scanf("%d",&t);
    while(t--){
        long long in;
        scanf("%lld",&in);
        bool ok=true;
        for(int i=0; i<=LIM; i++) if(!s[i] && in%i==0){
            ok=false;
            break;
        }
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
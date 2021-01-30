#include <cstdio>
 
int main() {
    int T;
    scanf("%d",&T);
    while(T--){
        int n, dgts=0, dgt[30];
        int sign=1;
        scanf("%d",&n);
        if(n<0){ sign=-1, n=-n; }
        do{
            dgt[dgts++]=n%3;
            n/=3;
        }while(n>0);
 
        int carry=0;
        for(int i=0; i<dgts; i++){
            dgt[i]+=carry;
            carry=0;
            if(dgt[i]>=2){
                dgt[i]-=3;
                carry=1;
            }
        }
        if(carry) dgt[dgts++]=1;
 
        for(int i=dgts-1; i>=0; i--){
            int curDgt=sign*dgt[i];
            if(curDgt==-1) printf("-");
            else printf("%d",curDgt);
        }
        printf("\n");
    }
    return 0;
}
#include <cstdio>
int main(void){
    int n,sol=0;
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        int t=i,s=0;
        while(t>0) s+=t%10, t/=10;
        s+=i;
        if(s==n){
            sol=i;
            break;
        }
    }
    printf("%d\n",sol);
    return 0;
}
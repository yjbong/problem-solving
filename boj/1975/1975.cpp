#include <stdio.h>
int main(void){
    int i,t,n,tmp,sol;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        sol=0;
        for(i=2; i<=n; i++){
            tmp=n;
            while(tmp>0){
                if(tmp%i==0){
                    sol++;
                    tmp/=i;
                }
                else break;
            }
        }
        printf("%d\n",sol);
    }
    return 0;
}
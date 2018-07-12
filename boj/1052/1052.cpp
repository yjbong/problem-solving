#include <cstdio>
int main(void){
    int n,k,i;
    scanf("%d %d",&n,&k);
    i=0;
    while(1){
        int t=n+i;
        int bit=0;
        while(t>0){
            if(t%2) bit++;
            t/=2;
        }
        if(bit<=k){
            printf("%d\n",i);
            break;
        }
        i++;
    }
    return 0;
}
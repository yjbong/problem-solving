#include <cstdio>
int d[1001],n;
int main(void){
        d[0]=0;
        for(int i=1; i<=1000; i++) d[i]=d[i-1]+i*(i+1)+(i*(i+1))/2;
        scanf("%d",&n);
        printf("%d\n",d[n]);
        return 0;
}
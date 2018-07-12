#include <cstdio>
#include <cmath>
int main(void){

    int n;
    scanf("%d",&n);
    if(n<=4) printf("4\n");
    else{
        int sq=(int)sqrt(n)-1;
        int sol;
        if((sq+1)*(sq+1)>=n) sol=sq*4;
        else if((sq+1)*(sq+2)>=n) sol=sol=sq*4+2;
        else sol=sq*4+4;
        printf("%d\n",sol);
    }
    return 0;
}
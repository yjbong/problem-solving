#include <stdio.h>
#define SWAP(a,b,tmp) {tmp=a;a=b;b=tmp;}
int main(void){
        int N, a, b, tmp;
        int round;
        scanf("%d %d %d", &N, &a, &b);
        if(a>b) SWAP(a,b,tmp);
        round=1;
        while(N>0){

                if(b-a==1 && (a+b+1)%4==0) break;
                a=a/2+a%2;
                b=b/2+b%2;
                N=N/2+N%2;
                round++;
        }
        if(N==0) printf("-1\n");
        else printf("%d\n", round);
        return 0;
}
#include <stdio.h>
#define SWAP(a,b) {tmp=a;a=b;b=tmp;}
int gcd(int a, int b){
        int tmp;
        if(b>a){
                SWAP(a,b);
        }

        while(b>0){
                a=a%b;
                SWAP(a,b);
        }
        return a;
}
int main(void){
        int i,j,cases;
        int n,m;
        int bunja, bunmo, common_div;
        scanf("%d", &cases);
        while(cases--){
                scanf("%d %d", &n, &m);
                if(n>m/2) n=m-n;
                bunja=bunmo=1;
                for(i=n, j=m; i>0; i--, j--){
                        bunja*=j;
                        bunmo*=i;
                        common_div=gcd(bunja,bunmo);
                        bunja/=common_div;
                        bunmo/=common_div;
                }
                printf("%d\n", bunja);
        }
        return 0;
}
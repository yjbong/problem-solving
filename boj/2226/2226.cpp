#include <stdio.h>
#define BIG 1000000000000000ll
long long a[30];
long long b[30];

int main(void){

    int i,j,n,carry;
    int first_print;

    scanf("%d", &n);

    if(n==1){
        printf("0\n");
    }
    else{

        a[0]=1;
        for(i=1; i<30; i++) a[i]=0;
        for(i=3; i<=n; i++){
            if(i%2==1) carry=-1;
            else carry=1;
            for(j=0; j<30; j++){
                a[j]+=a[j]+carry;
                carry=a[j]/BIG;
                a[j]%=BIG;
            }
        }

        first_print=1;
        for(i=29; i>=0; i--){
            if(first_print){
                if(a[i]>0 || i==0){
                    printf("%lld", a[i]);
                    first_print=0;
                }
            }
            else printf("%015lld", a[i]);
        }
        printf("\n");
    }
}
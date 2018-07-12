#include <stdio.h>
int main(void){

    long long a,b,c,left,mid,right,sol;
    scanf("%lld %lld %lld",&a,&b,&c);
    if(b>=c) printf("-1\n");
    else{
        left=1,right=2147483647;
        while(left<=right){
            mid=(left+right)/2;
            if(a+b*mid<c*mid){
                sol=mid;
                right=mid-1;
            }
            else left=mid+1;
        }
        printf("%lld\n",sol);
    }
    return 0;
}
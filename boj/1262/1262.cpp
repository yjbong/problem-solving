#include <stdio.h>
long long abs2(long long num){
    if(num<0) return (-num);
    else return num;
}

int main(void){

    long long i,j;
    long long n,r1,c1,r2,c2;

    long long rec_r, rec_c;
    long long cen_r, cen_c;
    long long diff;
    scanf("%lld %lld %lld %lld %lld", &n,&r1,&c1,&r2,&c2);
    for(i=r1; i<=r2; i++){
        for(j=c1; j<=c2; j++){
            rec_r=(i/(n*2-1))*(n*2-1);
            rec_c=(j/(n*2-1))*(n*2-1);

            cen_r=rec_r+n-1;
            cen_c=rec_c+n-1;

            diff=abs2(i-cen_r)+abs2(j-cen_c);
            if(diff>=n) printf(".");
            else printf("%c", diff%26+'a');
        }
        printf("\n");
    }
    return 0;
}
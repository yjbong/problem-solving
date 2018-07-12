#include <stdio.h>
int main(void){

    long long i,j,k,sol;
    long long N,r,c;
    while(scanf("%lld %lld %lld", &N, &r, &c)==3){

        sol=0;
        while(r>1 || c>1){
            i=1;
            while(i<=r) i*=2;
            i/=2;

            j=1;
            while(j<=c) j*=2;
            j/=2;

            if(i>j) k=i;
            else k=j;

            if(r>=k && c>=k){
                sol+=3*k*k;
                r-=k, c-=k;
            }
            else if(r>=k && c<k){
                sol+=2*k*k;
                r-=k;
            }
            else if(r<k && c>=k){
                sol+=1*k*k;
                c-=k;
            }
        }

        if(r==0 && c==0) sol+=0;
        else if(r==0 && c==1) sol+=1;
        else if(r==1 && c==0) sol+=2;
        else if(r==1 && c==1) sol+=3;
        printf("%lld\n", sol);
    }
    return 0;
}
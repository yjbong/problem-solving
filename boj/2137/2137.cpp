#include <stdio.h>
#define SWAP(a,b,t){t=a;a=b;b=t;}

typedef struct _bunsu{

        long long ja;
        long long mo;
}BUNSU;

long long abs2(long long a){

        if(a<0) return (-a);
        else return a;
}
long long gcd(long long a, long long b){

        int t;
        while(b>0){
                a%=b;
                SWAP(a,b,t);
        }
        return a;
}
long long cmp(BUNSU a, BUNSU b){

        long long diff;

        diff=a.ja*b.mo-b.ja*a.mo;
        return diff;
}

int main(void){

        long long i,q,d;
        BUNSU in,tot,loc,totd,locd;
        long long l,m,r;
        long long diff,min_diff;
        int f1,f2;
        scanf("%lld %lld",&in.ja,&in.mo);
        q=in.ja/in.mo;
        f1=1;
        for(i=1; i<32768; i++){
                l=q*i, r=(q+1)*i-1;
                f2=1;
                while(l<=r){
                        m=(l+r)/2;
                        diff=m*(in.mo)-(in.ja)*i;
                        if(diff<=0) l=m+1;
                        else r=m-1;

                        if(f2 || abs2(diff)<min_diff){

                                if(diff!=0){
                                        loc.ja=m,loc.mo=i;
                                        min_diff=abs2(diff);
                                }
                                f2=0;
                        }
                }

                if(f1){
                        tot.ja=loc.ja, tot.mo=loc.mo;
                        f1=0;
                }
                else{
                        totd.ja=abs2(tot.ja*in.mo-in.ja*tot.mo);
                        totd.mo=tot.mo*in.mo;
                        d=gcd(totd.ja,totd.mo);
                        totd.ja/=d,totd.mo/=d;

                        locd.ja=abs2(loc.ja*in.mo-in.ja*loc.mo);
                        locd.mo=loc.mo*in.mo;
                        d=gcd(locd.ja,locd.mo);
                        locd.ja/=d,locd.mo/=d;

                        if(cmp(totd,locd)>=0){
                                tot.ja=loc.ja, tot.mo=loc.mo;
                        }
                }
        }

        d=gcd(tot.ja,tot.mo);
        tot.ja/=d,tot.mo/=d;
        printf("%lld %lld\n",tot.ja,tot.mo);
        return 0;
}